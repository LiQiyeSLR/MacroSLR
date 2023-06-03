
#ifndef FADB_H
#define FADB_H

#include "../Windows Kits/10/Include/10.0.22000.0/um/Windows.h"
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/array"
#include "../MSVC/14.35.32215/include/memory"
#include "../MSVC/14.35.32215/include/ctime"
#include "../MSVC/14.35.32215/include/filesystem"
#include "../MSVC/14.35.32215/include/atomic"
#include "../MSVC/14.35.32215/include/chrono"
#include "../MSVC/14.35.32215/include/thread"
#include "../MSVC/14.35.32215/include/stdexcept"
#include "../MSVC/14.35.32215/include/cstdio"
#include "sysCommands.h"


class fadb
{
  public:
	  fadb();
	  ~fadb();
	std::string runADB(const std::string& command);
	void input(std::string input);
	void touch(int x, int y);
	void swipe(int x1, int y1, int x2, int y2, int delay);
	void setDim(int& DIMX, int& DIMY);
	void launch(std::string namepckg);
	void quit(std::string namepckg);
	void home();
	void back();
	void screenshotBusy();
	void screenshotEvents();
	void screenshot();
	bool connect();
	void disconnect();
	void kill();
	std::string getPID(std::string package);
	bool onApp(std::string package);
	bool onHome();
	void removeAllFiles(std::string dir_path);
	void wait(int time);
   private:
	   sysCommands sys;
};
#endif

