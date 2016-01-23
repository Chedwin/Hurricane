#include "Main.h"

#ifndef _STRING_H
	#include "string.h"
#endif

#ifndef _IOSTREAM_H
	#include "iostream.h"
#endif

#if defined(DEBUG) | defined(_DEBUG) 
int _tmain(int argc, char** argv) {
	// These two functions specify that we do not use these parameters
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	// Debugger::ConsoleLog("Starting Hurricane!");

	// Run the main function
	/*main(0, NULL);*/
	// Run WinMain subroutine
	WinMain((HINSTANCE)GetModuleHandle(NULL), 0, 0, SW_SHOW);
}
#endif

//int main(int argc, char** argv) 
//{
//	UNREFERENCED_PARAMETER(argc);
//	UNREFERENCED_PARAMETER(argv);
//


// Our main function
// btw -> HINSTANCE is a handle to an instance of an application. 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
		UNREFERENCED_PARAMETER(hInstance);
		UNREFERENCED_PARAMETER(hPrevInstance);
		UNREFERENCED_PARAMETER(lpCmdLine);
		UNREFERENCED_PARAMETER(nCmdShow);

#if defined(DEBUG) | defined(_DEBUG) 
	// Avoid memory leaks by catching them
	// Won't catch all of them (but you gotta catch 'em all right? lol)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	// Enable run-time memory leaks checks for debug builds
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// If a memory leak is found, the subroutine below will print to the 
	//	 output w/ the ID of the memory leak
	//_CrtSetBreakAlloc(0);
#endif

	// Make sure we're not running on a 64-bit machine
	static_assert(sizeof(void*) == 4, "64-bit code generation not supported!\n");


	exit(0);
}