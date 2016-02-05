//*******************************//
//
// Name:			stdio.h
// Description:		Includes stdio header files.
//					Detects what character byte system the engine is being used.
//
// Author:			Edwin Chen
// Created:			Feb 04, 2016
// Last updated:	Feb 04, 2016
//
//*******************************//

#ifndef _STDIO_H
#define _STDIO_H

#ifndef _STDIO
	#include <stdio.h>
#endif

#ifdef UNICODE
#define tprintf wprintf
#define tscanf  wscanf
#else 
#define tprintf printf
#define tscanf  scanf
#endif

#endif