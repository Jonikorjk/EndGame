#include "../inc/header.h"
#define NEXT_ENEMY (*cell_array)[1][i + 1].enemy[k]

void next_cell(t_cell ***cell_array, int i, int j) {
    t_enemy *temp = (*cell_array)[1][i].enemy[j];
    (*cell_array)[1][i].enemy[j] = NULL;
    for (int k = 0; k < MAX_COUNT_ENEMY; k++) {
        if (NEXT_ENEMY == NULL) {
            NEXT_ENEMY = temp;
            break;
        }
    }
}
#undef NEXT_ENEMY

