#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Coordinates.h"
#include "Texture.h"
#include "Player.h"
#include "Map.h"

using namespace std;

//TODO: move to game class and divide by init, mainLoop, exit and etc.
int main() {
    //TODO: make/apply window struct/class
    Coordinates mainWindowScale = {640, 480};

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    SDL_Window *win = SDL_CreateWindow("Racing game", 100, 100, mainWindowScale.x, mainWindowScale.y, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //TODO: relative path:
    const std::string gameFolder = "/home/alexander/Projects/programs/cpp/SDL/game1/";

    const std::string textureSubfolder = "res/img/";
    Texture carTexture(gameFolder + textureSubfolder + "car.png", ren, Coordinates(mainWindowScale.x / 2, mainWindowScale.y / 2));
    carTexture.scale *= 0.1;
    carTexture.positionOffset = carTexture.centerOffset();
    carTexture.angle = -90;
    Player car(&carTexture);

    Map map(Coordinates(20,20), ren, Coordinates(50,50), Coordinates(0,10), Coordinates());
    map.addTexture(gameFolder + textureSubfolder + "grass.jpg");

    SDL_Event event;
    SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF ); //white background

    //TODO:replace one cycle with std::thread multithreading:
    bool quit = false;
    while (!quit){

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            car.handleEvent(event);
        }

        car.handleControl();

        //Render the scene
        SDL_RenderClear(ren);

        map.render();
        map.move(Coordinates(0,0));

        carTexture.render();
        SDL_RenderPresent(ren);
        SDL_Delay(1000 / 60);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}