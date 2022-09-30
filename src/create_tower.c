#include "../inc/header.h" 

t_tower* createTower(enum tower_list type, SDL_Texture* texture, t_point spawn) {
    t_tower* newTower = malloc(sizeof(t_tower));
    
    switch (type) {
        case (TRO) :
            newTower->coolDown = 0.1f;
            newTower->baseDamage = 5;
            break;

        case (JAVELIN) :
            newTower->coolDown = 1.0f;
            newTower->baseDamage = 150;
            break;

        case (STINGER) :
            newTower->coolDown = 0.6f;
            newTower->baseDamage = 80;
            break;
    }

    newTower->tower_type = type;
    newTower->isAttacking = false;
    newTower->curTime = 0;
    newTower->dest.x = spawn.y;
    newTower->dest.y = spawn.x;
    newTower->tex = texture;

    SDL_QueryTexture(newTower->tex, NULL, NULL, &(newTower->dest.w), &(newTower->dest.h));

    newTower->dest.w = PROPOTION_X;
    newTower->dest.h = PROPOTION_Y; 

    return newTower;
}

