#include "Window.h"
#include "Debug.h"



Window::Window() : SDLWindow(nullptr), SDLRenderer(nullptr), SDLSurface(nullptr),
								winRect(), isInitialized(false), isFullScreen(false) {

}

Window::~Window() {
	Destroy();
}

bool Window::Initialize() {
	isInitialized = false;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
		Debug::Log(EMessageType::FATAL_ERR, "Window", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, std::string(SDL_GetError()));

#if defined(DEBUG) | defined(_DEBUG)
		// Set a breakpoint in DEBUG mode
		_CrtDbgBreak(); 
#endif
		return isInitialized;
	}

	// These attributes must be set before the SDL window is created 
	// TO DO: Add in SDL_GL calls later.....




	/// Create the SDL window
	SDLWindow = SDL_CreateWindow("Hurricane Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		winRect.w, winRect.h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (SDLWindow == nullptr) {
		Debug::Log(EMessageType::FATAL_ERR, "Window", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, std::string(SDL_GetError()));
		return isInitialized;
	}

	SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

	if (!SDLRenderer) {
		Debug::Log(EMessageType::FATAL_ERR, "Window", "Initialize", __TIMESTAMP__, __FILE__, __LINE__, std::string(SDL_GetError()));
		Destroy();
		return false;
	}


	Debug::ConsoleLog("Window created!");

	SDLSurface = SDL_GetWindowSurface(SDLWindow);
	SDL_SetRenderDrawColor(SDLRenderer, 100, 100, 100, 255);
	SDL_RenderFillRect(SDLRenderer, &winRect);
	SDL_RenderPresent(SDLRenderer);	
	ClearRenderer();

	isInitialized = true;
	return true;
}

void Window::Destroy() {
	SDL_DestroyWindow(SDLWindow);
	SDL_Quit();
	SDL_GL_DeleteContext(glContext);
	SDLWindow = nullptr;
	glContext = nullptr;
	isInitialized = false;
}

void Window::ClearRenderer() const {
	SDL_SetRenderDrawColor(SDLRenderer, 255, 255, 255, 255);
	SDL_RenderClear(SDLRenderer);
}

void Window::SetWindowSize(const int width_, const int height_) {
	winRect.w = width_;
	winRect.h = height_;
}

void Window::ToggleFullScreen() {
	isFullScreen = !isFullScreen;
	SDL_SetWindowFullscreen(SDLWindow, (isFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
}

SDL_Renderer* Window::GetRenderer() const {
	return SDLRenderer;
}

int Window::GetWidth() const {
	return winRect.w;
}

int Window::GetHeight() const {
	return winRect.h;
}