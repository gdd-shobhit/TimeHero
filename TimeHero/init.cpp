#include "init.h"
#include <SDL.h>
#include <stdio.h>
#include "core.h"

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

void Init(GameApp* app)
{
	InitSDL(app);
	// If i pass in app-> pTestMedia, it doesnt set the app-> testMedia to the loaded image
	// WHY?
	//LoadMedia(app-> pTestMedia);
	LoadMedia(app);
}

void LoadMedia(GameApp* app) 
{
	/*app->pTestMedia = SDL_LoadBMP("testMedia.bmp");
	if (app->pTestMedia == NULL)
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
	*/
}
void InitSDL(GameApp* app)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app->pWindow = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (app->pWindow == NULL)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}
	else
		app->pScreenSurface = SDL_GetWindowSurface(app->pWindow);		// gets window surface if window is already there

	app->pRenderer = SDL_CreateRenderer(app->pWindow, -1, 0);
	if (app->pRenderer == NULL)
	{
		printf("Failed to make %d x %d renderer: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}
}

