#include "sysCommands.h"



void sysCommands::time() {
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
void sysCommands::launchEmulator(const std::string& programPath, const std::string& exeName) {
    std::string command = "cd /d \"" + programPath + "\" && start \"\" " + exeName;
    std::system(command.c_str());
    //std::this_thread::sleep_for(std::chrono::seconds(20));
}

void sysCommands::launchBluestacksInstance(const std::string& programPath, const std::string& instanceName) {
    std::string command = "cd /d \"" + programPath + "\" && start \"\" \"HD-Player.exe\" --instance \"" + instanceName + "\"";
    std::system(command.c_str());
}
void sysCommands::shutdownEmulator(const string& appname) {
    string command = "taskkill /IM " + appname + " /T /F > nul 2>&1";
    std::system(command.c_str());
}

bool sysCommands::IsBlueStacksRunning() {
    const std::string bluestacksProcessName = "HD-Player.exe";
    const std::string command = "tasklist /FI \"IMAGENAME eq " + bluestacksProcessName + "\"";

    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to execute command." << std::endl;
        return false;
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string result=buffer;
        if (result.find(bluestacksProcessName) != std::string::npos) {
            _pclose(pipe);
            return true;
        }
    }
    _pclose(pipe);
    return false;
}

void sysCommands::filterLogcat(string command)
{
    command = "adb logcat | findstr " + command;
    std::system(command.c_str());
}

string sysCommands::concatcmd(const char*cmd1, const char*cmd2) {
    std::string result(cmd1);
    result += cmd2;
    return result.c_str();
}
string sysCommands::concatcmd(string cmd1, string cmd2) {
    std::string result(cmd1.c_str());
    result += cmd2;
    return result;
}
string sysCommands::concatcmd(const char* cmd1, string cmd2) {
    std::string result(cmd1);
    result += cmd2;
    return result;
}
string sysCommands::concatcmd(string cmd1, const char* cmd2) {
    std::string result(cmd1);
    result += cmd2;
    return result;
}


std::vector<std::string> sysCommands::getOutputCommand(std::string command) {
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        // Return an empty vector to indicate the failure
        return {};
    }

    char buffer[128];
    std::vector<std::string> outputLines;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line = buffer;
        cout << line;
        outputLines.push_back(line);
    }

    _pclose(pipe);

    // Return the vector containing all the output lines
    return outputLines;
}
void sysCommands::printFilteredLogs(const std::string& filter) {
    std::string command = "adb logcat | findstr " + filter;
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to execute command." << std::endl;
        return;
    }

    // Get the directory of the source file
    std::string sourceFilePath(__FILE__);
    std::string sourceDir = sourceFilePath.substr(0, sourceFilePath.find_last_of("\\/"));

    std::string logFilePath = sourceDir + "/log.txt";
    std::ofstream outputFile(logFilePath, std::ofstream::out | std::ofstream::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open log file." << std::endl;
        _pclose(pipe);
        return;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line = buffer;
        std::cout << line;

        outputFile << line;
        outputFile.flush();  // Ensure the content is written immediately

        // Read the content from the file and display it
        std::ifstream inputFile(logFilePath);
        std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
            std::istreambuf_iterator<char>());
        std::cout << "Content in log.txt: " << fileContent << std::endl;
        inputFile.close();
    }

    outputFile.close();
    _pclose(pipe);
}


bool sysCommands::StringInLogcat(const std::string& searchString) {
    std::string command = "adb logcat";
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command.c_str(), "r"), _pclose);
    if (!pipe) {
        std::cout << "Failed to execute logcat command." << std::endl;
        return false;
    }

    std::atomic<bool> foundString(false);  // Flag to indicate if the string is found
    char buffer[128];

    while (!foundString && fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        std::string line = buffer;

        if (line.find(searchString) != std::string::npos) {
            // The desired string is found, set the flag and terminate the logcat process
            cout << line;
            std::cout << "Found the string in logcat: " << searchString << std::endl;
            foundString = true;
            system("adb shell pkill logcat");  // Kill the logcat process
        }
    }

    return foundString;
    
}

std::string sysCommands::getParentDirectory() {
    std::filesystem::path currentFilePath(__FILE__);
    return currentFilePath.parent_path().parent_path().string();
}

std::string sysCommands::searchHDPlayerExecutable() {
    std::string path;

    if (path.empty()) {
        FILE* pipe = _popen("where /R \\ HD-Player.exe", "r");
        if (pipe) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
                std::string tempPath = buffer;
                tempPath.erase(tempPath.find_last_not_of("\r\n") + 1);
                std::cout << "System-wide search result: " << tempPath << std::endl;
                system("taskkill /F /IM where.exe");
                path = tempPath;
                break;
            }
            _pclose(pipe);
        }
    }

    return path;
}

std::string sysCommands::searchfile(const std::string& file) {
    std::string path;

    // Search for the file using the "where" command
    std::string command = "where /R \\ " + file;
    FILE* pipe = _popen(command.c_str(), "r");
    if (pipe) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::string tempPath = buffer;
            tempPath.erase(tempPath.find_last_not_of("\r\n") + 1);

            // Extract the folder path from the full file path
            std::filesystem::path fullPath(tempPath);
            std::filesystem::path folderPath = fullPath.parent_path();

            std::cout << "System-wide search result: " << folderPath.string() << std::endl;
            system("taskkill /F /IM where.exe");
            path = folderPath.string();
            break;
        }
        _pclose(pipe);
    }

    return path;
}

std::string sysCommands::getNameFolder(const std::string& fileName) {
    std::string searchPath = searchfile("grm_metadata.json");

    std::filesystem::path filePath(searchPath);
    for (const auto& entry : std::filesystem::recursive_directory_iterator(filePath)) {
        if (entry.is_regular_file() && entry.path().filename() == fileName) {
            std::filesystem::path parentPath = entry.path().parent_path();
            cout << parentPath.parent_path().filename().string();
            return parentPath.parent_path().filename().string();
        }
    }

    return ""; // Return empty string if file is not found
}

std::string sysCommands::readDiskLetter() {
    std::string diskLetter;
    std::ifstream file("diskletter.txt");
    if (file.is_open()) {
        std::getline(file, diskLetter);
        file.close();
    }
    else {
        std::cout << "Failed to open diskletter.txt" << std::endl;
    }
    std::cout << "Disk letter: " << diskLetter << std::endl;
    return diskLetter;
}


