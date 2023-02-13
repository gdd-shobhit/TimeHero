#pragma once
#include <SDL.h>
#include <SDL_test_images.h>
// UIComponent Class - Initializes a UI component with the image loaded.
// Contains functions to manipulate UI and re-render them;

class UIComponent
{
public:
	UIComponent(char* textureDestination, bool isInGame, bool isInStory);
	~UIComponent();
	void TranslateTo(uint16_t posX, uint16_t posY);
	void ClipTexuture(int x, int y, int width, int height);
	// Both false means HUD, health bars, weapon wheels etc
	bool isInGameSpace;				// like highlighting objects on selection, guiding UIs etc
	bool isInStory;					// ui Specific to story or the core gameplay like dialog boxes, special obstacles and guidelines like cracks, text on boulders, text on something else etc

// Properties
	SDL_Surface* GetTexture() { return pTexture; };
	uint16_t GetWidth() { return width; };
	uint16_t GetHeight() { return height; };
private:
	SDL_Surface* pTexture;
	uint16_t width;
	uint16_t height;
};

UIComponent::UIComponent (char* textureDestination, bool isInGameSpace, bool isInStory) {
	pTexture = SDL_LoadBMP(textureDestination);
	width = pTexture->w;
	height = pTexture->h;
	
	this->isInGameSpace = isInGameSpace;
	this->isInStory = isInStory;
}

UIComponent::~UIComponent() {
	SDL_free(this->pTexture);
}

/// <summary>
/// Transaltes to a position and Re-Renders the UI
/// </summary>
/// <param name="posX">x coordinate to translate to</param>
/// <param name="posY">y coordinate to translate to</param>
void UIComponent::TranslateTo(uint16_t posX, uint16_t posY)
{
}

void UIComponent::ClipTexuture(int x, int y, int width, int height)
{
	pTexture->clip_rect = SDL_Rect{ x, y, width, height}; // Clipping examples
}
