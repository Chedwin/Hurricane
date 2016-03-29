/// Welcome to Hurricane!
/// This source file is to test out the game engine features!

#include "Window.h"
#include "Graphics.h"
#include "Timer.h"

int main(int argc, char** agrv) {
	Window w;
	w.SetWindowSize(900, 600);
	w.Initialize();

	Graphics* g = new Graphics(w.GetRenderer());
	if (!g->ImgLoad("hurricane.bmp")) {
		std::cout << "Image failed!" << std::endl;
	}

	bool run = true;
	Timer timer;
	timer.Start();
	int fps = 10;
	while (run) {
		timer.UpdateFrameTicks();
		g->Draw();
		SDL_Delay(timer.GetSleepTime(fps));
	}

	g->Destroy();
	delete g;
	g = NULL;

	return 0;
}