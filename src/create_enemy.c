#include "../inc/header.h"

t_enemy* createEnemy(enum enemy_list type, SDL_Texture* texture, t_point spawn) {
    t_enemy* newEnemy = malloc(sizeof(t_enemy));
    
    newEnemy->tex = texture;
    SDL_QueryTexture(newEnemy->tex, NULL, NULL, &(newEnemy->dest.w), &(newEnemy->dest.h));

    switch (type) {
        case (SOLDIER) :
            newEnemy->max_hp = 160;
            newEnemy->maxTime = 1;
            newEnemy->speed = 80.0f / newEnemy->maxTime; 
            newEnemy->dest.w = 60;
            newEnemy->dest.h = 60;
            break;
        case (TANK) :
            newEnemy->max_hp = 460;
            newEnemy->maxTime = 0.6;
            newEnemy->speed = 80.0f / newEnemy->maxTime;
            newEnemy->dest.w = 250;
            newEnemy->dest.h = 150;
            break;
        case (HELICOPTER) :
            newEnemy->max_hp = 250;
            newEnemy->maxTime = 0.4;
            newEnemy->speed = 80.0f / newEnemy->maxTime; 
            newEnemy->dest.w = 250;
            newEnemy->dest.h = 200;
            break;
    }

    newEnemy->hp = newEnemy->max_hp;
    newEnemy->type = type;

    
    newEnemy->dest.x = spawn.y;
    newEnemy->dest.y = spawn.x; 

    return newEnemy;
}

