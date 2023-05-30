#include "SLRD.h"
#include "../Windows Kits/10/Include/10.0.22000.0/um/Windows.h"
#include "../Windows Kits/10/Include/10.0.22000.0/um/TlHelp32.h"
#include "../MSVC/14.35.32215/include/fstream"
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/ctime"
using namespace cv;

using namespace tesseract;

void time() {
   auto currentTime = std::chrono::system_clock::now();

    // Conversion du temps en un format lisible
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime;
    localtime_s(&localTime, &currentTimeT);

    // Extraction des composants de la date et de l'heure
    int year = localTime.tm_year + 1900; // Année
    int month = localTime.tm_mon + 1;    // Mois (janvier = 1)
    int day = localTime.tm_mday;         // Jour du mois
    int hour = localTime.tm_hour;        // Heure
    int minute = localTime.tm_min;       // Minute
    int second = localTime.tm_sec;       // Seconde

    // Affichage de la date et de l'heure
    std::cout << "Date et heure actuelles : "
        << day << "/" << month << "/" << year << " "
        << hour << ":" << minute << ":" << second << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(20));
}
void launchEmulator(const std::string& programPath, const std::string& appName) {
    std::string command = "cd /d \"" + programPath + "\" && start \"\" " + appName;
    std::system(command.c_str());
    std::this_thread::sleep_for(std::chrono::seconds(20));
}

void shutdownEmulator(const string&appname) {
    string command = "taskkill /IM " + appname + " /T /F > nul 2>&1";
    std::system(command.c_str());
  //  std::system("taskkill /IM HD-Player.exe /T /F > nul 2>&1");
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

bool IsBlueStacksRunning() {
    const std::string bluestacksProcessName = "HD-Player.exe";
    const std::string command = "tasklist /FI \"IMAGENAME eq " + bluestacksProcessName + "\"";

    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to execute command." << std::endl;
        return false;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string result(buffer);
        if (result.find(bluestacksProcessName) != std::string::npos) {
            _pclose(pipe);
            return true;
        }
    }

    _pclose(pipe);
    return false;
}


void detect_image(fadb& adb, fopencv& op, SLRD& sl) {
    while (true) {
        if (sl.endmacro)break;
        sl.findclickEvents(sl.busy);
        sl.findclickEvents(sl.reconnect);
        if (sl.findEvents(sl.waitconnexion)) {
            cout <<"X: " << sl.getEventx()<<endl;
            cout << "Y: " << sl.getEventy()<<endl;
            sl.waitMacro = true;
        }
        else sl.waitMacro = false;
    }
}

void stuck(SLRD&sl, int& MAXREBOOT) {
    while (true) {
        if (sl.endmacro)break;
        if (sl.getRebootCount() >= MAXREBOOT) {
            std::cout << "Relance du jeu\n"<<endl;
            sl.restartMacro = true;
        }
    }
}




int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
    fadb adb;
    fopencv op;
    ocr api;
    string EmulatorPath = "C:/Program Files/BlueStacks_nxt/";
    string appname = "HD-Player.exe";
    int dimX = 0;
    int dimY = 0;
    int MAXREBOOT = 50;
    if (IsBlueStacksRunning()) {
        shutdownEmulator(appname);
    }
    adb.kill();
    adb.connect();
    launchEmulator(EmulatorPath,appname);
    adb.wait(5000);
    adb.connect();
    adb.setDim(dimX, dimY);
    SLRD sl(dimX, dimY);
    std::thread image_detection_thread(detect_image, std::ref(adb), std::ref(op), std::ref(sl));
    std::thread not_detected_count_check_thread(stuck, std::ref(sl), std::ref(MAXREBOOT));
     sl.macroLoop();
    //sl.filterLogcat();
    image_detection_thread.join();
    not_detected_count_check_thread.join();
    return 0;
}


