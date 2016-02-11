#include "Debug.h"
#include "string.h"

using namespace CORE;

void Debug::Init(){
	std::ofstream out;

	// During this Init, we're going to either:
	// 1) Create "Log.txt" if it doesn't already exist, or
	// 2) Append to it if it exist
	out.open("Log.txt", std::ios::app | std::ios::out);

	out.close();
}

void Debug::Log(const EMessageType MsgType, const std::string& Class, const std::string& Method, const std::string& timestamp, const std::string& file, const int& line, const std::string& Comments)
{
	std::ofstream out;
	out.open("Log.txt", std::ios::app); // this will either create a new debug file or append to it

	switch (MsgType) {
	case EMessageType::INFO:
		out << timestamp << file << line << std::endl << "INFO: " << Class << "::" << Method << "()" << std::endl << "Notes: " << Comments << std::endl << std::endl;
		break;
	case EMessageType::WARNING:
		out << timestamp << file << line << std::endl << "WARNING: " << Class << "::" << Method << "()" << std::endl << "Notes: " << Comments << std::endl << std::endl;
		break;
	case EMessageType::ERR:
		out << timestamp << file << line << std::endl << "ERROR: " << Class << "::" << Method << "()" << std::endl << "Notes: " << Comments << std::endl << std::endl;
		break;
	case EMessageType::FATAL_ERR:
		out << timestamp << file << line << std::endl << "FATAL ERROR: " << Class << "::" << Method << "()" << std::endl << "Notes: " << Comments << std::endl << std::endl;
		break;
	}

	out.close(); // close the debug file
}


void Debug::ConsoleLog(const std::string& notes) {
	std::cout << notes << std::endl;
}

void Debug::ConsoleError(const std::string& error) {
	std::cerr << "ERROR: " << error << std::endl;
}