#ifndef SYSCOMMANDS_H
#define SYSCOMMANDS_H
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/array"
#include "../MSVC/14.35.32215/include/string"
#include "../MSVC/14.35.32215/include/memory"
#include "../MSVC/14.35.32215/include/ctime"
#include "../MSVC/14.35.32215/include/filesystem"
#include "../MSVC/14.35.32215/include/fstream"
#include "../MSVC/14.35.32215/include/atomic"
#include "../MSVC/14.35.32215/include/chrono"
#include "../MSVC/14.35.32215/include/thread"
#include "../MSVC/14.35.32215/include/stdexcept"
#include "../MSVC/14.35.32215/include/cstdio"
#include "../MSVC/14.35.32215/include/cstdlib"
#include "../Windows Kits/10/Include/10.0.22000.0/um/Windows.h"
#include "../Windows Kits/10/Include/10.0.22000.0/um/TlHelp32.h"
#include "../Windows Kits/10/Include/10.0.22000.0/ucrt/direct.h"




using namespace std;
class sysCommands
{
public:
	bool IsBlueStacksRunning();
	void shutdownEmulator(const string& appname);
	void filterLogcat(string command);
	void launchBluestacksInstance(const std::string& programPath, const std::string& instanceName);
	void launchEmulator(const std::string& programPath, const std::string& exename);
	bool stringLogcat(const std::string& searchString);
	std::vector<string> getOutputCommand(string command);
	string concatcmd(const char* cmd1, const char* cmd2);
	string concatcmd(string cmd1,const char* cmd2);
	string concatcmd(const char* cmd1, string cmd2);
	string concatcmd(string cmd1,string cmd2);
	void readLogcatOutput(const std::string filter, std::atomic<bool>& stopFlag);
	bool StringInLogcat(const std::string& searchString);
	vector<string> GetLogcatOutput(const std::string& searchString);
	void printFilteredLogs(const std::string& filter);
	void time();
	std::string searchfile(const string&file);
	std::string searchHDPlayerExecutable();
	std::string getParentDirectory();
	std::string getNameFolder(const std::string& fileName);
	std::string readDiskLetter();
	string disk;
	private:


};
#endif


