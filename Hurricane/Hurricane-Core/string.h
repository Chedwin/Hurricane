//*******************************//
//
// Name:			string.h
// Description:		Includes string and char header files.
//					Detects what character byte system the engine is being used.
//
// Author:			Edwin Chen
// Created:			Jan 20, 2016
// Last updated:	Feb 05, 2016
//
//*******************************//

#ifndef _STRING_H
#define _STRING_H

// Runtime header files
#ifndef _TCHAR_INC
#include <tchar.h>
#endif

#ifndef _STRING
	#include <string>
	typedef std::string eString;
#endif

// Use of Character Byte Systems for all spoken languages
#ifdef UNICODE
#define tstring wstring
#define TOSTRING(value) std::to_wstring
#else
#define tstring string
#define TOSTRING(value) std::to_string
#endif

#endif // end _STRING_H