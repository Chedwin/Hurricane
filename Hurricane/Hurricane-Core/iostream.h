//*******************************//
//
// Name:			iostream.h
// Description:		Includes string and char header files.
//					Detects what character byte system the engine is being used.
//
// Author:			Edwin Chen
// Created:			Jan 20, 2016
// Last updated:	Jan 20, 2016
//
//*******************************//

#ifndef _IOSTREAM_H
#define _IOSTREAM_H

// Runtime header files
#ifndef _IOSTREAM
	#include <iostream>
#endif

#ifdef UNICODE
#define tcout wcout 
#define tcin  wcin
#else 
#define tcout cout
#define tcin  cin
#endif


#endif // end _IOSTREAM_H