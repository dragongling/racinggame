#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"
#include "Coordinates.h"
Û‡Û‡ˆÈ‡







ˆÛ‡saferg'rhj 
rehrwlkhrt'
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
    Texture car(gameFolder + textureSubfolder + "car.png", ren, Coordinates(mainWindowScale.x / 2, mainWindowScale.y / 2));
    Texture grass(gameFolder + textureSubfolder + "grass.jpg", ren, Coordinates(0,0), Coordinates(50,50));
    car.scale *= 0.1;
    car.positionOffset = car.centerOffset();

    SDL_Event event;
    SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF ); //white background

    //TODO: move to map class or smth. similar:
    int a = 0;

    //TODO:replace one cycle with std::thread multithreading:
    bool quit = false;
    while (!quit){
        //TODO: move to player class:
        bool aright = false, aleft = false;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;

            //TODO: move to player class:
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
                aright = true;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
                aleft = true;
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RIGHT)
                aright = false;
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LEFT)
                aleft = false;
        }

        //TODO: move to player class:
        if(aright)
            car.angle++;
        if(aleft)
            car.angle--;

        //Render the scene
        SDL_RenderClear(ren);

        //TODO: move to map class or smth. similar:
        for(grass.position.y = a; grass.position.y < mainWindowScale.y; grass.position.y += grass.scale.y)
            for(grass.position.x = 0; grass.position.x < mainWindowScale.x; grass.position.x += grass.scale.x)
                grass.render();
        a++;
        if(a > grass.scale.y)
            a = 0;

        car.render();
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}