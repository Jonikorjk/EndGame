#include "../inc/header.h"

t_cell **init_cell_array(t_point *towers, int towers_count) {
    t_cell **array = malloc(sizeof(t_cell *) * PLAYABLE_HEIGHT);
    for (int i = 0; i < PLAYABLE_HEIGHT; i++) {
        array[i] = malloc(sizeof(t_cell) * PLAYABLE_WIDTH);
    }
    for (int i = 0; i < PLAYABLE_HEIGHT; i++) {
        for (int j = 0; j < PLAYABLE_WIDTH; j++) {
            for (int k = 0; k < MAX_COUNT_ENEMY; k++)
                array[i][j].enemy[k] = NULL;
            array[i][j].tower = NULL;
        }
    }
    return array;
}

