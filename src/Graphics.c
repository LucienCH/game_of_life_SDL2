#include "MainWindow.h"


int init_matrix(int width, int height){

    int nb_col = 100;
    int nb_row = 100;
    int cell_size = 10;

    int window_width = 0;
    int window_height = 0;

    // SDL_GetWindowSize(get_sdl_window(), &window_width, &window_height);

    // nb_row = (int)(window_width / (cell_size+2));
    // nb_col =  (int)(window_height / (cell_size+2));

    // printf("nb col : %d | nb rows : %d\n", nb_col, nb_row);

    // // printf("W : %d | H ; %d\n", window_width, window_height);

    // nb_col = 100;
    // nb_row = 100;
    SDL_Rect multi_rect[nb_col][nb_row];
    int cpt_col = 1;
    int cpt_row = 1;
    for (int i = 0; i < nb_row; i++){
        for(int j = 0; j < nb_col; j++){
            multi_rect[i][j].w = cell_size;
            multi_rect[i][j].h = cell_size;
            multi_rect[i][j].x = j * cell_size + cpt_col;
            multi_rect[i][j].y = i * cell_size + cpt_row;
            cpt_col++;
        }
        cpt_col = 1;
        cpt_row++;
    }
    SDL_SetRenderDrawColor(get_sdl_rederer(), 0, 0, 0, 255);
    SDL_RenderFillRects(get_sdl_rederer(), multi_rect, nb_row*nb_col);

    SDL_RenderPresent(get_sdl_rederer());


    return 0;

} 