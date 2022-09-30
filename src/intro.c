#include "../inc/header.h"

void intro(SDL_Renderer * renderer,
            SDL_Texture * texture,
            const SDL_Rect * srcrect,
            const SDL_Rect * dstrect) {
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
    SDL_RenderPresent(renderer);
    SDL_Delay(850);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);
    SDL_RenderClear(renderer);
}

