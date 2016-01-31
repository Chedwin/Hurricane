//*******************************//
//
// Name:			fstream.h
// Description:		Includes fstream header file.
//					Detects what character byte system the engine is being used.
//
// Author:			Edwin Chen
// Created:			Jan 31, 2016
// Last updated:	Jan 31, 2016
//
//*******************************//

#ifndef _FSTREAM_H
#define _FSTREAM_H

// Runtime header files
#ifndef _FOSTREAM
	#include <fstream>
#endif

#ifdef UNICODE
#define topen wopen
#define tclose wclose
#else 
#define topen open
#define tclose close
#endif


#endif // end _FSTREAM_H