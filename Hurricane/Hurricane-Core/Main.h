//*******************************//
//
// Name:			Main.h
// Description:		Forward declare the main source file
//
// Author:			Edwin Chen
// Created:			Jan 23, 2016
// Last updated:	Jan 31, 2016
//
//*******************************//

#ifndef _MAIN_H
#define _MAIN_H

#ifndef _WINDOW
	#include <Windows.h>
#endif

#ifndef _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif


int _tmain(int argc, char** argv);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);


#endif