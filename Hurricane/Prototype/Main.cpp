//*******************************//
//
// Welcome to the first ever Hurricane game!
//
//*******************************//


// Includes here
#include "Main.h"


// using namespaces here
using namespace GAME;

/// Necessary to undefine SDL main macro def ///
#undef main
////////////////////////////////////////////////

int main(int argc, char** argv) {

	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	/// Debug mode stuff
#if defined(DEBUG) | defined(_DEBUG)
	// Initialize the debug if it doesn't already exist
	Debug::Init();
	Debug::ConsoleLog("Welcome to the very first Hurricane game!");
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
	
	// Now for the real game!
	static_assert(sizeof(void*) == 4, "64-bit code generation not supported!\n");
	GameSceneManager::getInstance()->Run();

	return 0;
}