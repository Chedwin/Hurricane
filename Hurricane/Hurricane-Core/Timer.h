//*******************************//
//
// Name:			Timer.h
// Description:		Creates a timer that we can use anywhere we want
//					This includes our game loop
//
// Author:			Edwin Chen
// Created:			Mar 22, 2016
// Last updated:	Mar 22, 2016
//
//*******************************//

#ifndef TIMER_H
#define TIMER_H

namespace CORE {

	class Timer {
	private:
		unsigned int prevTicks;
		unsigned int currTicks;
	public:
		Timer();
		~Timer();

		// C11 precautions
		Timer(const Timer&) = delete;
		Timer(Timer&&) = delete;
		Timer& operator=(const Timer&) = delete;
		Timer& operator=(Timer&&) = delete;

		void Start();
		void UpdateFrameTicks();
		float GetDeltaTime() const;
		unsigned int GetSleepTime(const unsigned int fps) const;
	};

} // namespace GAME

#endif