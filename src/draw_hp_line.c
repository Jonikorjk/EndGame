#include "../inc/header.h"

void draw_hp_line(int max_hp, int hp, SDL_Rect dest, int type, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_Rect fillRect;
    if (type == SOLDIER) {
        fillRect = (SDL_Rect){dest.x, dest.y - 20, 74, 5};
    }
    else if (type == TANK) {
        fillRect = (SDL_Rect){dest.x, dest.y + 10, 170, 5};
    }
    else {
        fillRect = (SDL_Rect){dest.x, dest.y + 30, 220, 5};
    }
    SDL_RenderFillRect(renderer, &fillRect);
    float proportion = (float)(max_hp - hp) / (float)max_hp;
    SDL_Rect hpRect;
    if (type == SOLDIER) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        hpRect = (SDL_Rect){dest.x, dest.y - 20, (1 - proportion) * 74, 5};
    }
    else if (type == TANK) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        hpRect = (SDL_Rect){dest.x, dest.y + 10, (1 - proportion) * 170, 5};
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        hpRect = (SDL_Rect){dest.x, dest.y + 30, (1 - proportion) * 220, 5};
    }
    SDL_RenderFillRect(renderer, &hpRect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

