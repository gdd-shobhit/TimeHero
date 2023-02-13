#pragma once
#include "UIComponent.h"

#define CHARACTERS_IN_GAME 5

class UIManager
{
public:
	UIManager();
	~UIManager();
	
	SDL_Surface* textureSheets[CHARACTERS_IN_GAME];		// For now its in UIManager until i find a better place to store
														// the loaded bmps. Probably need an AssetManager / ResourceManager
	SDL_Rect* splashRectangles[CHARACTERS_IN_GAME];
private:
	const char* spriteSheets[5] = { "textures/ss_Zenitsu.bmp",
								"textures/ss_GiyoTomioka.bmp",
	"textures/ss_Kakashi.bmp",
	"textures/ss_Rengoku.bmp",
	"textures/ss_Zoro1.bmp" };
	int splashWidth = 70;
	int splashHeight = 70;
	int xy[CHARACTERS_IN_GAME][2] = { {140,20},
									  {170,20},
									  {100,90},
									  {140,20},
									  {140,20} };
};

UIManager::UIManager()
{
	for (uint8_t i = 0; i < CHARACTERS_IN_GAME; i++)
	{
		textureSheets[i] = SDL_LoadBMP(spriteSheets[i]);
		SDL_SetColorKey(textureSheets[i], SDL_TRUE, SDL_MapRGB(textureSheets[i]->format, 0x00, 0x80, 0x00));
		splashRectangles[i] = new SDL_Rect({xy[i][0],xy[i][1],splashWidth,splashHeight});
		SDL_Texture* sd;
	}
}

UIManager::~UIManager()
{
	
}
