#include "../inc/header.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    if (TTF_Init() != 0){
        printf("error initializing TTF: %s\n", TTF_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       SCR_WIDTH, SCR_HEIGHT, 0);
 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    

    t_point tower_spaces[TOWERS_COUNT] = {  (t_point){0,2}, (t_point){0,5}, (t_point){0,8}, (t_point){0,11},
                                (t_point){2,1}, (t_point){2,3}, (t_point){2,5}, 
                                (t_point){2,8}, (t_point){2,10}, (t_point){2,12}};
    
    t_point tower_check[6] = {(t_point){-1,0}, (t_point){-1,1}, (t_point){1,1}, 
                            (t_point){1,0}, (t_point){1, -1}, (t_point){-1,-1}};


    t_cell **cell_array = init_cell_array(tower_spaces, 4);

    TTF_Font *ourfont = TTF_OpenFont("resource/fonts/OpenSans-Bold.ttf", 64);
    SDL_Surface *textSurface = TTF_RenderText_Blended( ourfont, "500", (SDL_Color){255, 255, 0, 255});
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(rend, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect textRect;
    SDL_QueryTexture(text_texture, NULL, NULL, &(textRect.w), &(textRect.h));
    textRect.w = 80;
    textRect.h = 80;
    textRect.x = 1135;
    textRect.y = 555;

///////////////////////////
    SDL_Surface* s_surface = IMG_Load("resource/img/newswin.png");
    SDL_Texture* soldierTexture = SDL_CreateTextureFromSurface(rend, s_surface);
    SDL_FreeSurface(s_surface);

    SDL_Surface* t_surface = IMG_Load("resource/img/newtankproj1.png");
    SDL_Texture* tankTexture = SDL_CreateTextureFromSurface(rend, t_surface);
    SDL_FreeSurface(t_surface);    

    SDL_Surface* h_surface = IMG_Load("resource/img/newhelicopter1.png");
    SDL_Texture* helicopterTexture = SDL_CreateTextureFromSurface(rend, h_surface);
    SDL_FreeSurface(h_surface);
/////////////////////
    SDL_Surface* soldier_surface = IMG_Load("resource/img/tro.png");
    SDL_Surface* tank_surface = IMG_Load("resource/img/javelin.png");
    SDL_Surface* helicopter_surface = IMG_Load("resource/img/stinger.png");
    

    SDL_Texture* soldier_texture = SDL_CreateTextureFromSurface(rend, soldier_surface);
    SDL_Texture* tank_texture = SDL_CreateTextureFromSurface(rend, tank_surface);
    SDL_Texture* helicopter_texture = SDL_CreateTextureFromSurface(rend, helicopter_surface);

    SDL_Texture* towers_texture_array[3] = {soldier_texture, tank_texture, helicopter_texture};    

    //картинка менюшки
    SDL_Surface* menu_surface = NULL;
    menu_surface = IMG_Load("resource/img/menu.png");
    SDL_Texture* menu_tex = SDL_CreateTextureFromSurface(rend, menu_surface);
    SDL_FreeSurface(menu_surface);
    SDL_Rect menu_dest;
    SDL_QueryTexture(menu_tex, NULL, NULL, &menu_dest.w, &menu_dest.h);

    //картинка флага украины
    SDL_Surface* ukraine_surface = NULL;
    ukraine_surface = IMG_Load("resource/img/ukraine.png");
    SDL_Texture* ukraine_tex = SDL_CreateTextureFromSurface(rend, ukraine_surface);
    SDL_FreeSurface(ukraine_surface);
    SDL_Rect ukraine_dest;
    SDL_QueryTexture(ukraine_tex, NULL, NULL, &ukraine_dest.w, &ukraine_dest.h);

    //картинка флага россии
    SDL_Surface* russia_surface = NULL;
    russia_surface = IMG_Load("resource/img/russia.png");
    SDL_Texture* russia_tex = SDL_CreateTextureFromSurface(rend, russia_surface);
    SDL_FreeSurface(russia_surface);
    SDL_Rect russia_dest;
    SDL_QueryTexture(russia_tex, NULL, NULL, &russia_dest.w, &russia_dest.h);

    //картинка автомата
    SDL_Surface* rifle_surface = NULL;
    rifle_surface = IMG_Load("resource/img/rifle.png");
    SDL_Texture* rifle_tex = SDL_CreateTextureFromSurface(rend, rifle_surface);
    SDL_FreeSurface(rifle_surface);
    SDL_Rect rifle_dest;
    SDL_QueryTexture(rifle_tex, NULL, NULL, &rifle_dest.w, &rifle_dest.h);

    //credits
    SDL_Surface* credits_surface = NULL;
    credits_surface = IMG_Load("resource/img/credits.png");
    SDL_Texture* credits_tex = SDL_CreateTextureFromSurface(rend, credits_surface);
    SDL_FreeSurface(credits_surface);
    SDL_Rect credits_dest;
    SDL_QueryTexture(credits_tex, NULL, NULL, &credits_dest.w, &credits_dest.h);

    //lost 
    SDL_Surface* lost_surface = IMG_Load("resource/img/lost.png");
    SDL_Texture* lost_tex = SDL_CreateTextureFromSurface(rend, lost_surface);
    SDL_FreeSurface(lost_surface);
    SDL_Rect lost_dest;
    SDL_QueryTexture(lost_tex, NULL, NULL, &lost_dest.w, &lost_dest.h);

    //win 
    SDL_Surface* win_surface = IMG_Load("resource/img/win.png");
    SDL_Texture* win_tex = SDL_CreateTextureFromSurface(rend, win_surface);
    SDL_FreeSurface(win_surface);
    SDL_Rect win_dest;
    SDL_QueryTexture(win_tex, NULL, NULL, &win_dest.w, &win_dest.h);

    //картинка интро
    SDL_Surface* intro_surface = NULL;
    intro_surface = IMG_Load("resource/img/intro.png");
    SDL_Texture* intro_tex = SDL_CreateTextureFromSurface(rend, intro_surface);
    SDL_FreeSurface(intro_surface);
    SDL_Rect intro_dest;
    SDL_QueryTexture(intro_tex, NULL, NULL, &intro_dest.w, &intro_dest.h);

        //картинка поля боя
    SDL_Surface* field_surface = NULL;
    field_surface = IMG_Load("resource/img/field.png");
    SDL_Texture* field_tex = SDL_CreateTextureFromSurface(rend, field_surface);
    SDL_FreeSurface(field_surface);
    SDL_Rect field_dest;
    SDL_QueryTexture(field_tex, NULL, NULL, &field_dest.w, &field_dest.h);

        //interface
    SDL_Surface* interface_surface = IMG_Load("resource/img/interface.png");
    SDL_Texture* interface_tex = SDL_CreateTextureFromSurface(rend, interface_surface);
    SDL_FreeSurface(interface_surface);
    SDL_Rect interface_dest;
    SDL_QueryTexture(interface_tex, NULL, NULL, &interface_dest.w, &interface_dest.h);
    interface_dest.x = 1120;
    interface_dest.y = 0;
    interface_dest.w = 160;
    interface_dest.h = 720;
//


    int close = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
//
    Mix_Music* menu_music = Mix_LoadMUS("resource/sound/bandera.mp3");
    Mix_Music* game_music = Mix_LoadMUS("resource/sound/soundtrack.mp3");
    Mix_Music* lost_music = Mix_LoadMUS("resource/sound/lose.mp3");
    Mix_Music* win_music = Mix_LoadMUS("resource/sound/victory.mp3");
    Mix_Chunk*  initTRO = Mix_LoadWAV("resource/sound/tro.wav");
    Mix_Chunk* initYanik = Mix_LoadWAV("resource/sound/yanik.wav");
    Mix_Chunk* tankDestroy = Mix_LoadWAV("resource/sound/tank.wav");
    Mix_Chunk* helicopterDestroy = Mix_LoadWAV("resource/sound/dispetcher.wav");
    Mix_Chunk* TroFight = Mix_LoadWAV("resource/sound/ak.wav");
    Mix_Chunk* JavelinFight = Mix_LoadWAV("resource/sound/javelin.wav");
    Mix_Chunk* StingerFight = Mix_LoadWAV("resource/sound/stinger.wav");

    menu_dest.w /= 1.5;
    menu_dest.h /= 1.5;
    menu_dest.x = (SCR_WIDTH - menu_dest.w) / 2;
    menu_dest.y = (SCR_HEIGHT - menu_dest.h) / 2;

    rifle_dest.w /= 2;
    rifle_dest.h /= 2;
    rifle_dest.x = 630;
    rifle_dest.y = 70;

    credits_dest.w = menu_dest.w;
    credits_dest.h = menu_dest.h;
    credits_dest.x = menu_dest.x;
    credits_dest.y = menu_dest.y;

    field_dest.w = menu_dest.w;
    field_dest.h = menu_dest.h;
    field_dest.x = menu_dest.x;
    field_dest.y = menu_dest.y;

    intro_dest.w = menu_dest.w;
    intro_dest.h = menu_dest.h;
    intro_dest.x = menu_dest.x;
    intro_dest.y = menu_dest.y;

    lost_dest.w = menu_dest.w;
    lost_dest.h = menu_dest.h;
    lost_dest.x = menu_dest.x;
    lost_dest.y = menu_dest.y;

    win_dest.w = menu_dest.w;
    win_dest.h = menu_dest.h;
    win_dest.x = menu_dest.x;
    win_dest.y = menu_dest.y;



    double deltaTime = 0;
    double globalTime = 0;
    double spawnTime = 0;

    bool menu = 1;
    bool you_lost = 0;
    bool you_win = 0;
    bool credits = 0;
    bool game = 0;
    bool timeToZero = 0;

    int whoToBuy;

    int money = 500;
    int lastTickMoney = money;

    Mix_PlayMusic(menu_music, -1);

    while (!close) {
        

        SDL_RenderClear(rend);
        

        SDL_Event event;
        // Events management
        while (SDL_PollEvent(&event)) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            switch (event.type) {
                case SDL_QUIT:
                    // handling of close button
                    close = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN :
                    printf("%i", x);
                    printf(" ");
                    printf("%i", y);
                    printf("\n");
                    if (!game) {
                        if (x > 445 && x < 690 && y > 190 && y < 300 && menu) {
                            menu = 0;
                            game = 1;
                            you_lost = 0;
                            you_win = 0;
                            money = 500;
                            globalTime = 0;
                            timeToZero = 1;
                            Mix_PlayMusic(game_music, -1);
                            intro(rend, intro_tex, NULL, &intro_dest);
                        }
                        else if (x > 470 && x < 680 && y > 335 && y < 385 && !credits) {
                            credits = 1;
                            menu = 0;
                        }
                        else if (x > 475 && x < 600 && y > 420 && y < 475 && menu) {
                            close = 1;
                            break;
                        }
                        else if (x > 0 && x < 230 && y > 0 && y < 60 && credits) {
                            credits = 0;
                            menu = 1;
                        }
                        if ((you_lost || you_win) 
                        || (x >= 1120 && y >= 640)) {
                            menu = 1;
                            you_lost = 0;
                            you_win = 0;
                        }
                    }
                    else {
                        if (x > 1125 && x < 1275 ) {
                            if (y > 645 && y < 695) {
                                game = 0;
                                menu = 1;
                                free_cells(cell_array, tower_spaces);   
                                Mix_PlayMusic(menu_music, -1);
                            }
                            if (y > 25 && y < 160) {
                                whoToBuy = TRO;
                            }
                            if (y > 200 && y < 340) {
                                whoToBuy = JAVELIN;
                            }
                            if (y > 375 && y < 520) {
                                whoToBuy = STINGER;
                            }
                        }
                        else if (y > 400 && y < 480) {
                                if (x > 160 && x < 240) {
                                    spawn_tower(cell_array, whoToBuy, &money, tower_spaces[0], (t_point){160, 400}, towers_texture_array, initTRO, initYanik);
                                }
                                if (x > 400 && x < 480) {
                                    spawn_tower(cell_array, whoToBuy, &money, tower_spaces[1], (t_point){400, 400}, towers_texture_array, initTRO, initYanik);
                                }
                                if (x > 640 && x < 720) {
                                    spawn_tower(cell_array, whoToBuy, &money, tower_spaces[2], (t_point){640, 400}, towers_texture_array, initTRO, initYanik);
                                }
                                if (x > 880 && x < 960) {
                                    spawn_tower(cell_array, whoToBuy, &money, tower_spaces[3], (t_point){880, 400}, towers_texture_array, initTRO, initYanik);
                                }
                        }
                        else if (y > 560 && y < 640) {
                            if (x > 80 && x < 160) {
                                spawn_tower(cell_array, whoToBuy, &money, tower_spaces[4], (t_point){80, 560}, towers_texture_array, initTRO, initYanik);
                            }
                            if (x > 240 && x < 320) {
                                spawn_tower(cell_array, whoToBuy, &money, tower_spaces[5], (t_point){240, 560}, towers_texture_array, initTRO, initYanik);
                            }
                            if (x > 400 && x < 480) {
                                spawn_tower(cell_array, whoToBuy, &money, tower_spaces[6], (t_point){400, 560}, towers_texture_array, initTRO, initYanik);
                            }
                            if (x > 640 && x < 720) {
                                spawn_tower(cell_array, whoToBuy, &money, tower_spaces[7], (t_point){640, 560}, towers_texture_array, initTRO, initYanik);
                            }
                            if (x > 800 && x < 880) {
                                spawn_tower(cell_array, whoToBuy, &money, tower_spaces[8], (t_point){800, 560}, towers_texture_array, initTRO, initYanik);
                            }
                            if (x > 960 && x < 1040) {
                                spawn_tower(cell_array, whoToBuy, &money, tower_spaces[9], (t_point){960, 560}, towers_texture_array, initTRO, initYanik);
                                
                            }
                        }
                    }
            }
        }
        double time = (double)SDL_GetTicks() / 1000;
        SDL_RenderClear(rend);

        if (menu) {
            ukraine_dest.w = (20 * sin(time * 3) + 150) * 1.2;
            ukraine_dest.h = ukraine_dest.w * 9 / 16;
            ukraine_dest.x = (SCR_WIDTH - ukraine_dest.w) / 2 - 120;
            ukraine_dest.y = (SCR_HEIGHT - ukraine_dest.h) / 2 - 270;

            russia_dest.w = (20 * sin(time * 3 - 3.14) + 150) / 1.2;
            russia_dest.h = russia_dest.w * 9 / 16;
            russia_dest.x = (SCR_WIDTH - russia_dest.w) / 2 + 180;
            russia_dest.y = (SCR_HEIGHT - russia_dest.h) / 2 - 270;

            SDL_RenderCopy(rend, menu_tex, NULL, &menu_dest);
            SDL_RenderCopyEx(rend, ukraine_tex, NULL, &ukraine_dest, 10 * sin(time * 3), NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(rend, russia_tex, NULL, &russia_dest, -10 * sin(time * 3), NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(rend, rifle_tex, NULL, &rifle_dest, -10 * sin(time * 3), NULL, SDL_FLIP_NONE);
        }
        else if (credits) {
            SDL_RenderCopy(rend, credits_tex, NULL, &credits_dest);
        }
        else if (you_lost) {
            SDL_RenderCopy(rend, lost_tex, NULL, &lost_dest);
        }
        else if (you_win) {
            SDL_RenderCopy(rend, win_tex, NULL, &win_dest);
        }
        else if (game) {
            if(lastTickMoney != money) {
                textSurface = TTF_RenderText_Blended(ourfont, itoa(money), (SDL_Color){180, 180, 0, 255});
                text_texture = SDL_CreateTextureFromSurface(rend, textSurface);
                SDL_FreeSurface(textSurface);
                //SDL_QueryTexture(text_texture, NULL, NULL, &(textRect.w), &(textRect.h));
                //textRect.w = 120;
                //textRect.h = 80;
            }
            lastTickMoney = money;

            //time 

            /// ///
            Uint32 ticks = SDL_GetTicks();
            Uint32 seconds = ticks / 125;
            Uint32 spriteTankAndSoldier = seconds % 6;
            Uint32 spriteHelicopter = seconds % 4;

            SDL_Rect forSoldierAnim = { spriteTankAndSoldier * 166, 0, 166, 200 };
            SDL_Rect forTankAnim = {spriteTankAndSoldier * 250, 0, 250, 100};
            SDL_Rect forHelicopterAnim = {spriteHelicopter * 250, 0, 250, 200};
            //////

            LAST = NOW;
            NOW = SDL_GetPerformanceCounter();
            deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
            globalTime += deltaTime;

            if (timeToZero) {
                deltaTime = 0;
                timeToZero = 0;
                int enemy_count = 1;
                int chance = rng(1, 100);
                for (int i = 0, k = 0; k < enemy_count; i++) {
                    if(!cell_array[1][0].enemy[i]) {
                        k++;
                        chance = rng(1, 100);
                        if (chance > 85) {
                            cell_array[1][0].enemy[i] = createEnemy(HELICOPTER, helicopterTexture, (t_point){rng(-85, -75), rng(250, 300)});
                        }
                        else if (chance > 70) {
                            cell_array[1][0].enemy[i] = createEnemy(TANK, tankTexture, (t_point){rng(-85, -75), rng(410, 435)});
                        }
                        else {
                            cell_array[1][0].enemy[i] = createEnemy(SOLDIER, soldierTexture, (t_point){rng(-85, -75), rng(440, 465)});    
                        }
                    }
                    if(i == MAX_COUNT_ENEMY - 1)
                        break;             
                }
            }

            SDL_RenderCopy(rend, field_tex, NULL, &field_dest);

            if (globalTime > 258) {
                you_win = 1;
                game = 0; 
                Mix_PlayMusic(win_music, -1);
                free_cells(cell_array, tower_spaces);
                continue;
            } 

            if (globalTime < 250) {
                spawnTime += deltaTime;
                float randNum = (440 - (sqrt(globalTime) * 25)) / 100.0f;
                if (spawnTime >= randNum) {
                    spawnTime -= randNum; 
                    int enemy_count = 1;
                    int chance = rng(1, 100);
                    if (chance > 90) {
                        enemy_count = 2;
                        if (chance > 95)
                            enemy_count = 3;
                    }
                    for (int i = 0, k = 0; k < enemy_count; i++) {
                        if(!cell_array[1][0].enemy[i]) {
                            k++;
                            chance = rng(1, 100);
                            if (chance > 85 - (int)(globalTime / 12)) {
                                cell_array[1][0].enemy[i] = createEnemy(HELICOPTER, helicopterTexture, (t_point){rng(-85, -75), rng(250, 300)});
                            }
                            else if (chance > 70 - ((int)(globalTime / 12) * 2)) {
                                cell_array[1][0].enemy[i] = createEnemy(TANK, tankTexture, (t_point){rng(-85, -75), rng(410, 435)});
                            }
                            else {
                                cell_array[1][0].enemy[i] = createEnemy(SOLDIER, soldierTexture, (t_point){rng(-85, -75), rng(440, 465)});    
                            }
                        }    
                        if(i == MAX_COUNT_ENEMY - 1)
                            break;             
                    }
                }          
            }
        
            for (int i = 0; i < TOWERS_COUNT; i++) {
                #define THIS_TOWER cell_array[tower_spaces[i].y][tower_spaces[i].x].tower
                if (THIS_TOWER) {
                    THIS_TOWER->curTime += deltaTime;
                    SDL_RenderCopy(rend, THIS_TOWER->tex, NULL, &(THIS_TOWER->dest));
                }
                #undef THIS_TOWER
            }
            for (int i = PLAYABLE_WIDTH - 1; i >= 0; i--) {
                for (int j = 0; j < MAX_COUNT_ENEMY; j++) {
                    #define THIS_ENEMY cell_array[1][i].enemy[j]
                    if (THIS_ENEMY != NULL) {
                        int checkForTowers = i;
                        if (checkForTowers == PLAYABLE_WIDTH - 1)
                            checkForTowers -= 1;
                        if (checkForTowers == 0)
                            checkForTowers += 1;
                        for (int k = 0; k < TOWER_CHECKER_LENGTH; k++) {
                            #define THIS_TOWER cell_array[1 + tower_check[k].y][checkForTowers + tower_check[k].x].tower
                            if (THIS_TOWER != NULL) {
                                if (THIS_TOWER->isAttacking) {
                                    if (THIS_TOWER->curTime < THIS_TOWER->coolDown)
                                        continue;
                                }
                                THIS_TOWER->isAttacking = true;
                                THIS_TOWER->curTime = 0;
                                switch (THIS_TOWER->tower_type)
                                        {
                                        case TRO:
                                            if (rng(1, 100) > 70) Mix_PlayChannel(3, TroFight, 0);
                                            break;
                                        
                                        case STINGER:
                                            if (rng(1, 100) > 40) Mix_PlayChannel(4, StingerFight, 0);
                                            break;

                                        case JAVELIN:
                                            if (rng(1, 100) > 40) Mix_PlayChannel(5, JavelinFight, 0);
                                            break;
                                        }

                                int applied_damage = THIS_TOWER->baseDamage;

                                switch (THIS_TOWER->tower_type) {
                                    case TRO:
                                        if (THIS_ENEMY->type == SOLDIER) applied_damage *= 1.5;
                                        if (THIS_ENEMY->type == TANK) applied_damage /= 1.5;
                                        break;

                                    case JAVELIN:
                                        if (THIS_ENEMY->type == TANK) applied_damage *= 1.5;
                                        if (THIS_ENEMY->type == HELICOPTER) applied_damage /= 1.5;
                                        break;

                                    case STINGER:
                                        if (THIS_ENEMY->type == HELICOPTER) applied_damage *= 1.5;
                                        if (THIS_ENEMY->type == SOLDIER) applied_damage /= 1.5;
                                        break;
                                }    
                                THIS_ENEMY->hp -= applied_damage;
                                if (THIS_ENEMY->hp <= 0) 
                                    break;
                            }
                        }

                        if (THIS_ENEMY->hp <= 0) {
                            switch (THIS_ENEMY->type)
                            {
                                case SOLDIER:
                                    money += 10;
                                    break;

                                case TANK:
                                    if (rng(1,100) > 70) 
                                        Mix_PlayChannel(7, tankDestroy, 0);
                                    money += 30;
                                    break;

                                case HELICOPTER:
                                    if (rng(1,100) > 80) 
                                        Mix_PlayChannel(6, helicopterDestroy, 0);
                                    money += 30;
                                    break;
                            }
                            free(THIS_ENEMY);
                            THIS_ENEMY = NULL;
                            continue;
                        }
                        
                        THIS_ENEMY->tempDistance += (80.0f * deltaTime) / THIS_ENEMY->maxTime;
                        THIS_ENEMY->curTime += deltaTime;


                        int dist_to_coords = (int)(THIS_ENEMY->tempDistance);
                        THIS_ENEMY->tempDistance -= dist_to_coords;

                        THIS_ENEMY->dest.x += dist_to_coords;

                        /////////////////////////////
                        if(THIS_ENEMY->type == SOLDIER) {
                            SDL_RenderCopy(rend, THIS_ENEMY->tex, &forSoldierAnim, &(THIS_ENEMY->dest));
                        }
                        else if(THIS_ENEMY->type == TANK) {
                            SDL_RenderCopy(rend, THIS_ENEMY->tex, &forTankAnim, &(THIS_ENEMY->dest));
                        }
                        else if(THIS_ENEMY->type == HELICOPTER) {
                            SDL_RenderCopyEx(rend, THIS_ENEMY->tex, &forHelicopterAnim, &(THIS_ENEMY->dest), 15, NULL, SDL_FLIP_NONE);
                        }
                        ///////////

                        draw_hp_line(THIS_ENEMY->max_hp, THIS_ENEMY->hp, THIS_ENEMY->dest, THIS_ENEMY->type, rend);

                        if (THIS_ENEMY->type == SOLDIER 
                        && THIS_ENEMY->curTime >= THIS_ENEMY->maxTime) {
                            THIS_ENEMY->curTime = 0;
                            if (i == PLAYABLE_WIDTH - 1) {
                                game = 0;
                            }
                            next_cell(&cell_array, i, j);
                        }
                        else if (THIS_ENEMY->type == TANK 
                        && THIS_ENEMY->curTime >= THIS_ENEMY->maxTime) {
                            THIS_ENEMY->curTime = 0;
                            if (i == PLAYABLE_WIDTH - 1) {
                                game = 0;
                            }
                            next_cell(&cell_array, i, j);
                        }
                        else if (THIS_ENEMY->type == HELICOPTER 
                        && THIS_ENEMY->curTime >= THIS_ENEMY->maxTime) {
                            THIS_ENEMY->curTime = 0;
                            if (i == PLAYABLE_WIDTH - 1) {
                                game = 0;
                            }
                            next_cell(&cell_array, i, j);
                        }
                        if(!game)
                            break;
                    } 
                    if(!game) {
                        break;
                    }
                } 
                if(!game) {
                    free_cells(cell_array, tower_spaces);
                    you_lost = 1;
                    Mix_PlayMusic(lost_music, -1);
                    break;
                }
            }
            SDL_RenderCopy(rend, interface_tex, NULL, &(interface_dest));
            SDL_RenderCopy(rend, text_texture, NULL, &(textRect));
        }
        SDL_RenderPresent(rend);
        SDL_Delay(1000 / 60);
    }

    free_cells(cell_array, tower_spaces);


    for (int i = 0; i < PLAYABLE_HEIGHT; i++) {
        free(cell_array[i]);
        cell_array[i] = NULL;
    }

    free(cell_array);
    cell_array = NULL;

    TTF_CloseFont(ourfont);

    SDL_FreeSurface(soldier_surface);
    SDL_FreeSurface(tank_surface);
    SDL_FreeSurface(helicopter_surface);
    SDL_DestroyTexture(soldier_texture);
    SDL_DestroyTexture(tank_texture);
    SDL_DestroyTexture(helicopter_texture);
    SDL_DestroyTexture(menu_tex);
    SDL_DestroyTexture(ukraine_tex);
    SDL_DestroyTexture(russia_tex);
    SDL_DestroyTexture(rifle_tex);
    SDL_DestroyTexture(interface_tex);
    Mix_FreeMusic(menu_music);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    
 
    return 0;
}

