//*******************************//
//
// Name:			Audio.h
// Description:		Creates an abstract class Audio
//					Music headers will override this class
//
// Author:			Edwin Chen
// Created:			Mar 24, 2016
// Last updated:	Mar 24, 2016
//
//*******************************//

#ifndef AUDIO_H
#define AUDIO_H

#include <string>


	class Audio {
	public:
		Audio();
		virtual ~Audio();

		void SetMasterVolume(const int MasterVolume) const;
		int GetMasterVolume() const;

		/// Pure viturals
		virtual bool Load(const std::string& FileName) = 0;
		virtual void Play(const int LoopCount = 0) const = 0;
		virtual void SetVolume(int Volume) const = 0;
		virtual void Destroy() = 0;
	protected:
	private:
	};


#endif