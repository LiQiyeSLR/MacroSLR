#include "fadb.h"

using namespace std;

fadb::fadb(){
}
fadb::~fadb() {

}

void fadb::input(string input) {
    runADB(sys.concatcmd("input ",input));
}
void fadb::touch(int x, int y) {
    string x_str = to_string(x);
    string y_str = to_string(y);
    string command = "tap " + x_str + " " + y_str;
    input(command);
}
void fadb::swipe(int x1, int y1, int x2, int y2, int delay) {
    string x1_str = to_string(x1);
    string y1_str = to_string(y1);
    string x2_str = to_string(x2);
    string y2_str = to_string(y2);
    string delay_str = to_string(delay);
    string command = "swipe " + x1_str + " " + y1_str + " " + x2_str + " " + y2_str + " " + delay_str;
    input(command);
}
std::string fadb::runADB(const std::string& command)
{
    std::string adb = "adb shell ";
    
    std::string fullCommand = sys.concatcmd(adb,command);

    std::array<char, 128> buffer;
    std::string result;

    FILE* pipe = _popen(fullCommand.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Error: Failed to open pipe for command: " << fullCommand << std::endl;
        return "";
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr)
    {
        result += buffer.data();
    }

    _pclose(pipe);

    return result;
}

void fadb::setDim(int& DIMX, int& DIMY) {
    string output = runADB("wm size");
   string dimension = output.substr(output.find_last_of(" ") + 1);
    string dimX = "";
    string dimY = "";
    int i = 0;
    while (dimension[i] != 'x') {
        dimX += dimension[i];
        i++;
    }
    i++;
    int startdimY = i;
    while (dimension[i] != ' ') {
        dimY += dimension[i];
        i++;
    }
    dimY.erase(remove(dimY.begin(), dimY.end(), '\r'), dimY.end());
    dimY.erase(remove(dimY.begin(), dimY.end(), '\n'), dimY.end());
    DIMX = stoi(dimX);
    DIMY = stoi(dimY);
}
void fadb::launch(string namepckg) {
    runADB("am start -n " + namepckg);
}
void fadb::quit(string namepckg) {
    runADB("am force-stop " + namepckg);

}

void fadb::home() {
    input("keyevent KEYCODE_HOME");
}
void fadb::back() {
    input("keyevent KEYCODE_BACK");
}
void fadb::removeAllFiles(string dir_path) {
    for (auto& file : filesystem::directory_iterator(dir_path)) { // Iterate over the directory
        if (filesystem::is_regular_file(file)) { // Check if it's a file (not a directory)
            remove(file.path().string().c_str()); // Remove the file
        }
    }
}
void fadb::screenshot() {
    //removeAllFiles("./img");
    string command = "screencap -p ./sdcard/screenshot.png";
    string commandPull = "adb pull /sdcard/screenshot.png ./img";
    runADB(command);
    system(commandPull.c_str());

}
void fadb::screenshotEvents() {
    //removeAllFiles("./img");
    string command = "screencap -p ./sdcard/screenshotEvents.png";
    string commandPull = "adb pull /sdcard/screenshotEvents.png ./img";
    runADB(command);
    system(commandPull.c_str());

}
void fadb::screenshotBusy() {
    //removeAllFiles("./img");
    string command = "screencap -p ./sdcard/screenshotBusy.png";
    string commandPull = "adb pull /sdcard/screenshotBusy.png ./img";
    runADB(command);
    system(commandPull.c_str());

}
bool fadb::connect()
{
    int result = system("adb connect localhost");

    // Check the return value of the command
    if (result == 0)
    {
        std::cout << "Connected to adb." << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to connect to adb." << std::endl;
        return false;
    }
}
void fadb::disconnect() {
    system("adb disconnect");
}

string fadb::getPID(string package) {
    string output = runADB(" ps | grep " + package);
    string PID = output.substr(10, 5);
    return PID;
}

bool fadb::onHome() {
    string output = runADB("dumpsys window windows | grep -E 'mFocusedApp='");
    if (output.find("HomeActivity") != string::npos) {
        std::cout << "On Home Screen " << endl;
        return true;
    }
    else {
        cout << "not home "<<endl;
        return false;
    }
}

void fadb::kill() {
    system("adb kill-server");
}

bool fadb::onApp(string package) {
    string output = runADB("dumpsys window windows | grep -E 'mFocusedApp='");
    if (output.find(package) != string::npos) {
        std::cout << "On " + package << endl;
        return true;
    }
    else {
        cout << "not on "+package<<endl;
        return false;
    }
}

void fadb::wait(int time) {
    this_thread::sleep_for(chrono::milliseconds(time));
}