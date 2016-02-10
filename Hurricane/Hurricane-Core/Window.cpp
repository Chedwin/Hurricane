#include "Window.h"
#include "Debug.h"

Window::Window() : isInitialized(false), windowPtr(nullptr), isFullScreen(false) {
	OnCreate();
}

Window::~Window() {
	OnDestroy();
}

bool Window::OnCreate() {
	isInitialized = false;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
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
	windowPtr = SDL_CreateWindow("Component Framework Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		winRect.w, winRect.h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (windowPtr == nullptr) {
		Debug::Log(EMessageType::FATAL_ERR, "Window", "OnCreate", __TIMESTAMP__, __FILE__, __LINE__, std::string(SDL_GetError()));
		return isInitialized;
	}

	isInitialized = true;
	return true;
}

void Window::OnDestroy() {
	SDL_DestroyWindow(windowPtr);
	SDL_Quit();
	SDL_GL_DeleteContext(glContext);
	windowPtr = nullptr;
	glContext = nullptr;
	isInitialized = false;
}

void Window::SetWindowSize(const int width_, const int height_) {
	winRect.w = width_;
	winRect.h = height_;
}


void Window::ToggleFullScreen() {
	isFullScreen = !isFullScreen;
	SDL_SetWindowFullscreen(windowPtr, (isFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
}


int Window::GetWidth() const {
	return winRect.w;
}

int Window::GetHeight() const {
	return winRect.h;
}