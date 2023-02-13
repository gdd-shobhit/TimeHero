/* Title:   Time Hero
*  Summary: Game where you can bend time, solve puzzlesand kill enemies.
*  Genre:   HackNSlash, Puzzle, Rogue like
  Key Features:
  1) Time Essence: Bends the time (Slows everything except yourself)
*/

#include <stdio.h>
#include "core.h"
#include "init.h"
#include "draw.h"
#include "UIComponent.h"
#include "UIManager.h"
#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

int WinMain()
{
	GameApp* app = new GameApp();
	Init(app);

    //UIComponent* kakashiTest = new UIComponent((char*)"textures/ss_zenitsu.bmp", false, false);    // does casting to char* works?
    //SDL_Rect* srcRect = new SDL_Rect({140,20,60,70});
    UIManager* uiManager = new UIManager();
    SDL_Texture* bgTex = SDL_CreateTextureFromSurface(app->pRenderer,SDL_LoadBMP("textures/charSelectBg.bmp"));
    int w;
    int h;
    SDL_QueryTexture(bgTex, NULL, NULL, &w, &h); // get the width and height of the texture
    SDL_Rect* something = new SDL_Rect({ 0,0,w,h });
    SDL_RenderCopy(app->pRenderer, bgTex, NULL, something);
  
    SDL_Rect* destRect = new SDL_Rect({ 500,500,60,70 });
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (count >= 3)
        {
            count = 0;
            destRect->y += 100;
            destRect->x = 500;
        }
        SDL_BlitSurface(uiManager->textureSheets[i], uiManager->splashRectangles[i], app->pScreenSurface, destRect);
        destRect->x += 80;
        count++;
    }
    SDL_BlitSurface(uiManager->textureSheets[1], new SDL_Rect({ 1100,300, 480, 800}), app->pScreenSurface, new SDL_Rect({ 0,0, 480, 800 }));
    SDL_BlitSurface(uiManager->textureSheets[0], new SDL_Rect({ 800,300, 480, 800 }), app->pScreenSurface, new SDL_Rect({ 800,0, 480, 800 }));
    //Update the surface
    SDL_Surface* test = SDL_GetWindowSurface(app->pWindow);
    SDL_SetColorKey(test, SDL_TRUE, SDL_MapRGB(test->format, 0x00, 0x00, 0x00));
    SDL_RenderCopy(app->pRenderer, SDL_CreateTextureFromSurface(app->pRenderer, test), NULL, NULL);
    SDL_RenderPresent(app->pRenderer);
    /*SDL_UpdateWindowSurface(app->pWindow);*/
   
    //Hack to get window to stay up
    SDL_Event e; bool quit = false; 
    while (quit == false) {
        while (SDL_PollEvent(&e)) 
        { 
            if (e.type == SDL_QUIT) 
                quit = true; 
        }  
    }
    Close(app);
    return 0;
}

void Close(GameApp* app)
{
    //Deallocate surface
    SDL_FreeSurface(app->pScreenSurface);
    app->pScreenSurface = nullptr;

    //Destroy window
    SDL_DestroyWindow(app->pWindow);
    app->pWindow = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}