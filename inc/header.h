#ifndef HEADER_H
#define HEADER_H

#define SCR_WIDTH 1280
#define SCR_HEIGHT 720
#define F_WIDTH 16
#define F_HEIGHT 9 
#define PROPOTION_X SCR_WIDTH/F_WIDTH
#define PROPOTION_Y SCR_HEIGHT/F_HEIGHT
#define TOWER_CHECKER_LENGTH 6
#define MAX_COUNT_ENEMY 100
#define PLAYABLE_WIDTH 15
#define PLAYABLE_HEIGHT 3 
#define TOWERS_COUNT 10

#include "../resource/include/SDL2/SDL.h"
#include "../resource/include/SDL2/SDL_ttf.h"
#include "../resource/include/SDL2/SDL_timer.h"
#include "../resource/include/SDL2/SDL_mixer.h"
#include "../resource/include/SDL2/SDL_image.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <unistd.h>


enum enemy_list {
    SOLDIER = 1,
    TANK = 2,
    HELICOPTER = 3
};


typedef struct s_point{
    int y;
    int x;
} t_point;

typedef struct s_enemy {
    // let us control our image position
    // so that we can move it with our keyboard.
    SDL_Rect dest;
    SDL_Texture *tex;

    enum enemy_list type;
    float maxTime;
    float curTime;
    double speed;
    double tempDistance;
    int hp;
    int max_hp;
} t_enemy;

enum tower_list {
    TRO = 1,
    JAVELIN = 2,
    STINGER = 3
};


typedef struct s_tower {
    int tower_type;
    bool isAttacking;
    double coolDown;
    double curTime;
    int baseDamage; 
    

    SDL_Rect dest;
    SDL_Texture *tex;

} t_tower;

// можно отправлять в функцию перемещения клетки которые уже дороги 
typedef struct s_cell {
    t_tower *tower; 
    t_enemy *enemy[MAX_COUNT_ENEMY];

} t_cell;




void spawn_tower(t_cell **cell_array, int whoToBuy, int *money, 
                t_point cell, t_point render_coords, 
                SDL_Texture **texture_array,
                Mix_Chunk* soundToPlay, Mix_Chunk* soundToPlays);
t_tower* createTower(enum tower_list type, SDL_Texture* texture, t_point spawn);

t_enemy* createEnemy(enum enemy_list type, SDL_Texture* texture, t_point spawn);
t_cell **init_cell_array(t_point *towers, int towers_count);
void next_cell(t_cell ***cell_array, int i, int j);
void free_cells(t_cell **cell_array, t_point *tower_spaces);
void intro(SDL_Renderer * renderer, SDL_Texture * texture,
            const SDL_Rect * srcrect, const SDL_Rect * dstrect);
void draw_hp_line(int max_hp, int hp, SDL_Rect dest, int type, SDL_Renderer *renderer);
int rng(int min, int max);
char *itoa(int n);
char *mx_strdup(const char *str);
char* mx_strcpy(char* dst, const char* src);
char *mx_strjoin(char const *s1, char const *s2);
int mx_strlen(const char*s);
char *mx_strnew(const int size);
char *mx_strcat(char *s1, const char *s2);

#endif

