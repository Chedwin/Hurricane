#include "Audio.h"
#include "SDL_Adapter.h"

using namespace CORE;

Audio::Audio() {
	// empty....
}
Audio::~Audio() {
	// empty....
}


void Audio::SetMasterVolume(const int MasterVolume) const {
	Mix_Volume(-1, MasterVolume);
}

int Audio::GetMasterVolume() const {
	return Mix_Volume(-1, -1);
}