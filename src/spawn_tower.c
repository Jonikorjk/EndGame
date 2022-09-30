#include "../inc/header.h"

#define THIS_TOWER cell_array[cell.y][cell.x].tower

void spawn_tower(t_cell **cell_array, int whoToBuy, int *money, t_point cell, t_point render_coords, SDL_Texture **texture_array,
Mix_Chunk* soundToPlay, Mix_Chunk* soundToPlays) {
    if (THIS_TOWER) {
        int current_type = THIS_TOWER->tower_type;
        if(current_type == whoToBuy) {
            free(THIS_TOWER);
            THIS_TOWER = NULL;
            return;
        }
    }
    if (whoToBuy == TRO && *money >= 100) {
        THIS_TOWER = createTower(TRO, texture_array[0], render_coords);
        *money -= 100;
        Mix_PlayChannel(2, soundToPlay, 0);
    }
    else if (whoToBuy == JAVELIN && *money >= 300) {
        THIS_TOWER = createTower(JAVELIN, texture_array[1], render_coords);
        *money -= 300;
    }
    else if (whoToBuy == STINGER && *money >= 300) {
        THIS_TOWER = createTower(STINGER, texture_array[2], render_coords);
        *money -= 300;
        Mix_PlayChannel(2, soundToPlays, 0); 
    }   
}
#undef THIS_TOWER

