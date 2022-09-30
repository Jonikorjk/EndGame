#include "../inc/header.h"
#define THIS_TOWER cell_array[tower_spaces[i].y][tower_spaces[i].x].tower
#define THIS_ENEMY cell_array[1][i].enemy[j]
void free_cells(t_cell **cell_array, t_point *tower_spaces) {
    for (int i = 0; i < PLAYABLE_WIDTH; i++) {
        for (int j = 0; j < MAX_COUNT_ENEMY; j++) {
            if(THIS_ENEMY) {
                free(THIS_ENEMY);
                THIS_ENEMY = NULL;   
            }
        }
    }
    for (int i = 0; i < TOWERS_COUNT; i++) {
        if (THIS_TOWER) {
            free(THIS_TOWER);
            THIS_TOWER = NULL;  
        }
    } 
}
#undef THIS_TOWER
#undef THIS_ENEMY

