//*******************************//
//
// Welcome to Hurricane!
//
//*******************************//

#ifndef _MAIN_H
	#include "Main.h"
#endif

#ifndef _STRING_H
	#include "string.h"
#endif

#ifndef _IOSTREAM_H
	#include "iostream.h"
#endif

#ifndef _DEBUG_H
	#include "Debug.h"
#endif

// state our using namespaces here
using namespace CORE;


#if defined(DEBUG) | defined(_DEBUG) 
int _tmain(int argc, char** argv) {
	// These two functions specify that we do not use these parameters
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	Debug::ConsoleLog("Starting Hurricane!");

	// Run WinMain function
	WinMain((HINSTANCE)GetModuleHandle(NULL), 0, 0, SW_SHOW);
}
#endif



// Our main function
// btw -> HINSTANCE is a "handle" to an instance of an application. 
//		In our case, the main function!
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
		UNREFERENCED_PARAMETER(hInstance);
		UNREFERENCED_PARAMETER(hPrevInstance);
		UNREFERENCED_PARAMETER(lpCmdLine);
		UNREFERENCED_PARAMETER(nCmdShow);

#if defined(DEBUG) | defined(_DEBUG)
	// Initialize the debug if it doesn't already exist
	Debug::Init();

	// Avoid memory leaks by catching them
	// Won't catch all of them (but you gotta catch 'em all right? lol)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	// Enable run-time memory leaks checks for debug builds
	// By default, this function will call _CrtDumpMemoryLeaks() at any exit point
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// If a memory leak is found, the main function will NOT return 0
	// This will trigger the breakpoint below to find the mem leak
	if (!_CrtSetBreakAlloc(0)) {
		Debug::ConsoleError("MEMORY LEAK DETECTED");
		Debug::Log(EMessageType::ERR, "Main", "Main", __TIMESTAMP__, __FILE__, __LINE__, "MEMORY LEAK DETECTED");
		_CrtDbgBreak();
	}
	
#endif

	// Make sure we're not running on a 64-bit machine
	static_assert(sizeof(void*) == 4, "64-bit code generation not supported!\n");
	
	//TO DO:

	// Call the engine's run function
	// The run function should create the engine instance if it doesn't already exist
	//HurricaneEngine::getInstance()->Run();

	// That's it!
	// the main function should be this small!
	exit(0);
}