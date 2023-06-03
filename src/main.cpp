#include "SLRD.h"

#include "../Windows Kits/10/Include/10.0.22000.0/um/Windows.h"
#include "../Windows Kits/10/Include/10.0.22000.0/um/TlHelp32.h"
#include "../MSVC/14.35.32215/include/fstream"
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/ctime"
using namespace cv;
using namespace tesseract;



void detect_busy(SLRD& sl) {
    while (true) {
        if (sl.endmacro)break;
        if (sl.findclickBusy(sl.busy))sl.waitMacro = true;
        else sl.waitMacro = false;
    }
}

void detect_image(SLRD& sl) {
    while (true) {
        if (sl.endmacro)break;
        if(sl.findclickEvents(sl.reconnect))sl.waitMacro = true;
        else sl.waitMacro = false;
        if (sl.findEvents(sl.waitconnexion))sl.waitMacro = true;
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
    sysCommands sys;
    string exename = "HD-Player.exe";

    int dimX = 0;
    int dimY = 0;
    int MAXREBOOT = 50;
    char currentDir[256];
    sys.disk = sys.readDiskLetter();
    
    if (!_getcwd(currentDir, sizeof(currentDir))) {
        std::cerr << "Failed to get current working directory." << std::endl;
        return 1;
    }
    std::string EmulatorPath = sys.searchHDPlayerExecutable();
    if (_chdir(currentDir) != 0) {
        std::cerr << "Failed to restore the original working directory." << std::endl;
        return 1; // or handle the error as needed
    }
    string slrinstance = sys.getNameFolder("com.soullandrl.gp.png");
    
    if (sys.IsBlueStacksRunning()) {
        sys.shutdownEmulator(exename);
    }
    adb.kill();
    adb.connect();
    cout << slrinstance << endl;
    sys.launchBluestacksInstance(EmulatorPath, slrinstance);
    adb.wait(10000);
    adb.connect();
    adb.setDim(dimX, dimY);
    SLRD sl(dimX, dimY);
    std::thread image_detection_thread(detect_image, std::ref(sl));
    std::thread not_detected_count_check_thread(stuck, std::ref(sl), std::ref(MAXREBOOT));
    std::thread busy_thread(detect_busy, std::ref(sl));
    sl.macroLoop();
    
    image_detection_thread.join();
    not_detected_count_check_thread.join();
    busy_thread.join();
    return 0;
}


