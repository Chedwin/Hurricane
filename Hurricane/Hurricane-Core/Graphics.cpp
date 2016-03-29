#include "Graphics.h"
#include <SDL_image.h>
#include "Debug.h"


Graphics::Graphics(SDL_Renderer* sdlRenderer) : SDLTexture(nullptr), SDLRenderer(sdlRenderer), width(0), height(0) {

}

Graphics::~Graphics() {
	Destroy();
}

bool Graphics::ImgLoad(const std::string& FileName) {
	Destroy();
	SDL_Texture* NewSDLTexture = nullptr;

	SDL_Surface* LoadedSurface = IMG_Load(FileName.c_str());
	if (!LoadedSurface) {
		Debug::Log(EMessageType::ERR, "Graphics", "Load", __TIMESTAMP__, __FILE__, __LINE__, "Failed to load " + FileName + ". SDL Error: " + SDL_GetError());
	}
	else {
		if (SDL_SetColorKey(LoadedSurface, SDL_TRUE, SDL_MapRGB(LoadedSurface->format, 0, 0xFF, 0xFF)) < 0) {
			Debug::Log(EMessageType::ERR, "Graphics", "Load", __TIMESTAMP__, __FILE__, __LINE__, "Failed to set color key for " + FileName + ". SDL Error: " + SDL_GetError());
		}

		NewSDLTexture = SDL_CreateTextureFromSurface(SDLRenderer, LoadedSurface);
		if (!NewSDLTexture) {
			Debug::Log(EMessageType::ERR, "Graphics", "Load", __TIMESTAMP__, __FILE__, __LINE__, "Failed to create Graphics from " + FileName + ". SDL Error: " + SDL_GetError());
		}
		else {
			width = LoadedSurface->w;
			height = LoadedSurface->h;
		}

		SDL_FreeSurface(LoadedSurface);
		LoadedSurface = nullptr;
	}

	SDLTexture = NewSDLTexture;
	return SDLTexture != nullptr;
}



void Graphics::Destroy() {
	SDL_DestroyTexture(SDLTexture);
	SDLTexture = nullptr;
	width = 0;
	height = 0;
}

void Graphics::Draw(const DrawParams& Params) const {
	SDL_Rect DrawRect = {
		(int)(Params.x + (-width * (Params.scale - 1.0f) * 0.5f)),
		(int)(Params.y + (-height * (Params.scale - 1.0f) * 0.5f)),
		(int)(width * Params.scale),
		(int)(height * Params.scale) };

	if (Params.clip) {
		DrawRect.w = Params.clip->w;
		DrawRect.h = Params.clip->h;
	}

	SDL_RenderCopyEx(SDLRenderer, SDLTexture, Params.clip, &DrawRect, Params.angle, Params.center, Params.flip);
}

void Graphics::Draw(const int x, const int y, const float scale,
	SDL_Rect* clip, const double angle,
	SDL_Point* center, const SDL_RendererFlip flip) const
{
	DrawParams params = DrawParams{ x, y, scale, clip, angle, center, flip };
	Draw(params);
}




/// Setter subroutines
void Graphics::SetTexture(SDL_Texture& SDLTexture_, const int width_, const int height_) {
	Destroy();
	SDLTexture = &SDLTexture_;
	width = width_;
	height = height_;
}

void Graphics::SetAlpha(const Uint8 a_) {
	SDL_SetTextureAlphaMod(SDLTexture, a_);
}

void Graphics::SetBlendMode(const SDL_BlendMode blendMode_) {
	SDL_SetTextureBlendMode(SDLTexture, blendMode_);
}

void Graphics::SetColor(const SDL_Color& SDLColor_) {
	SetColor(SDLColor_.r, SDLColor_.g, SDLColor_.b, SDLColor_.a);
}

void Graphics::SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) {
	SDL_SetTextureColorMod(SDLTexture, r, g, b);
	SDL_SetTextureAlphaMod(SDLTexture, a);
}

int Graphics::GetWidth() const {
	return width;
}

int Graphics::GetHeight() const {
	return height;
}