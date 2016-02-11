//*******************************//
//
// Name:			Debug.h
// Description:		I/O streams for debugging.
//					Opens a debug file for writing.
//
// Author:			Edwin Chen
// Created:			Jan 31, 2016
// Last updated:	Feb 05, 2016
//
//*******************************//

#ifndef _DEBUG_H
#define _DEBUG_H 

#include "iostream.h"
#include "fstream.h"

namespace CORE {

	/// This enum is a simple 8-bit unsigned int
	enum class EMessageType : unsigned short {
		INFO = 0,
		WARNING,
		ERR,
		FATAL_ERR
	};

	class Debug {
	public:
		/// New in C++ 11: this deletes the automatic constructor from being formed if no other constructor is decleared 
		Debug() = delete;

		/// Let's kill any default constructors the complier makes for us
		Debug(const Debug&) = delete;
		Debug(Debug&&) = delete;
		Debug& operator=(const Debug&) = delete;
		Debug& operator=(Debug&&) = delete;

		static void Init();
		static void Log(const EMessageType MsgType, const std::string& Class, const std::string& Method, const std::string& timestamp, const std::string& file, const int& line, const std::string& Comments);
		static void ConsoleLog(const std::string& notes);
		static void ConsoleError(const std::string& error);
	};

} // end namespace CORE

#endif