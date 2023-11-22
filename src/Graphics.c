#include "Common.h"


SDL_Rect** game_grid;

int initMatrix(int width, int height){

    int cell_size = 4;
    int window_width = 0;
    int window_height = 0;

    //printf("nb_col %d nb_row %d\n", worldWidth, worldHeight);

    SDL_GetWindowSize(get_sdl_window(), &window_width, &window_height);

    SDL_SetRenderDrawColor(get_sdl_rederer(), 0, 0, 0, 255);

    game_grid = malloc(sizeof(SDL_Rect) * worldHeight);

    if(!game_grid){
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < worldHeight; i++){
        game_grid[i] = malloc(sizeof(SDL_Rect) * worldWidth);
    }
    
    int cpt_col = 1;
    int cpt_row = 1;
    for (int i = 0; i <  worldWidth; i++){
        for(int j = 0; j < worldHeight; j++){

            game_grid[i][j].w = cell_size;
            game_grid[i][j].h = cell_size;
            game_grid[i][j].x = j * cell_size + cpt_col;
            game_grid[i][j].y = i * cell_size + cpt_row;
            cpt_col++;
        }
        cpt_col = 1;
        cpt_row++;
    }
    
    return 0;
}

void change_grid_state(){
    for(int i = 0; i <  worldWidth; i++){
        for(int j = 0; j < worldHeight; j++){
            if(get_cell_state(j,i) == DEAD){
                SDL_SetRenderDrawColor(get_sdl_rederer(), 255, 255, 255, 255);
            }else{
                SDL_SetRenderDrawColor(get_sdl_rederer(), 0, 0, 0, 255);
            }
            SDL_RenderFillRect(get_sdl_rederer(), &game_grid[i][j]);
        }
    }
    SDL_RenderPresent(get_sdl_rederer());
}

void freeSDLRect(){
    free(game_grid);
}