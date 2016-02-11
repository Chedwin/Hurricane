#include "HuricaneEngine.h"

using namespace CORE;

std::unique_ptr<HurricaneEngine> HurricaneEngine::hEngineInstance(nullptr);

HurricaneEngine::HurricaneEngine() : windowInstance(), isRunning(false), frameRate(30) {
	// empty Hurricane game engine constructor 
	// BORING
}

HurricaneEngine::~HurricaneEngine() {
	// NOTE: windowInstance is a STACK variable 
	//		 Therefore: you do NOT need to call its destructor
	windowInstance.OnDestroy();
	isRunning = false;
}

HurricaneEngine* HurricaneEngine::getInstance(){
	if (hEngineInstance.get() == nullptr){
		/// I originally set the unique_ptr to be null in the constructor - 
		/// reset() sets the new address

		// NOTE: this is where the constructor ACTUALLY gets called
		hEngineInstance.reset(new HurricaneEngine());
	}
	return hEngineInstance.get();
}
