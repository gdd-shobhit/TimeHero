#pragma once
#include <SDL.h>
typedef struct {
	SDL_Renderer* pRenderer;
	SDL_Window* pWindow;
	SDL_Surface* pScreenSurface;
} GameApp;

void Close(GameApp* app);