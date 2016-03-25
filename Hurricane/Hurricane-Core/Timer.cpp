#include "Timer.h"
#include "SDL_Adapter.h"

using namespace CORE;

Timer::Timer() :prevTicks(0), currTicks(0) {} // single colon operator : here pre-initializes the variables

Timer::~Timer() {}

void Timer::UpdateFrameTicks() {
	prevTicks = currTicks;
	currTicks = SDL_Adapter::ReturnTicks();
}

void Timer::Start() {
	prevTicks = SDL_Adapter::ReturnTicks();
	currTicks = SDL_Adapter::ReturnTicks();
}

float Timer::GetDeltaTime() const {
	return (currTicks - prevTicks) / 1000.0f;
}

unsigned int Timer::GetSleepTime(const unsigned int fps) const {
	unsigned int milliSecsPerFrame = 1000 / fps;
	if (milliSecsPerFrame == 0) {
		return 0;
	}

	unsigned int sleepTime = milliSecsPerFrame - (SDL_Adapter::ReturnTicks());
	if (sleepTime > milliSecsPerFrame) {
		return milliSecsPerFrame;
	}

	return sleepTime;
}