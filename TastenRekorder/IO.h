#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"
#include "Helper.h"
#include "Base64.h"

namespace IO
{
	std::string GetOurPath(const bool append_seperator = false)
	{
		// Creating directory 
		std::string appdata_dir(getenv("APPDATA"));
		std::string full = appdata_dir + "\\Microsoft\\CLR";
		return full + (append_seperator ? "\\" : "");
	}

	bool MkOneDR(std::string path)
	{
		return (bool)CreateDirectory(path.c_str(), NULL) ||
			GetLastError() == ERROR_ALREADY_EXISTS;
	}
}
#endif // IO_H