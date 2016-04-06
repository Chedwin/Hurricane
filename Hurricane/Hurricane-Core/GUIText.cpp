#include "GUIText.h"


bool triggerOffset = false;
GUIText::GUIText(Window *_windowRef) :textSurface(nullptr), font(nullptr), box(new SDL_Rect{ 0, 0, 0, 0 }), windowRef(nullptr) {
	windowRef = _windowRef;
}

GUIText::~GUIText() {
	SDL_FreeSurface(textSurface);
}

bool GUIText::Load(const char *_text, int _r, int _g, int _b, SDL_Rect *_box, int _size) {
	char* finalText;
	std::string cutString;
	cutString = std::string(_text);
	if (TTF_Init() != 0) {
		Debug::ConsoleError("TTF_Init() failed");
		return false;
	}
	font = TTF_OpenFont("../Dependencies/fonts/Montserrat-Regular.ttf", _size);
	if (font == nullptr) {
		Debug::ConsoleError("Failed to load font");
		return false;
	}
	fontColour = { (Uint8)_r, (Uint8)_g, (Uint8)_b };
	box->y = _box->y;
	box->h = _box->h;
	box->w = strlen(_text) * _size;

	int maxChar = _box->w / _size;
	int totalChars = maxChar + offset;

	int cursorPosition = cutString.find("_"); //position number = character before cursor, therefore +1 and that's its position
	if (cursorPosition > maxChar) {
		offset = (cursorPosition + 1) - maxChar;
	}
	else if (cursorPosition < offset) {
		offset -= 1;
	}

	box->x = _box->x - (offset * _size);
	textSurface = TTF_RenderText_Solid(font, cutString.c_str(), fontColour);
	offsetPrev = offset;
	if (textSurface)
		textSurface->clip_rect = *_box;
	text = _text;
	return true;
}



void GUIText::Update(float deltaTime) {

	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(windowRef->GetRenderer(), textSurface);
	SDL_RenderCopy(windowRef->GetRenderer(), textTexture, NULL, box);
	atexit(TTF_Quit);
}