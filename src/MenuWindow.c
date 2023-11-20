#include "MenuWindow.h"

#define NB_RECT_MENU 3

SDL_Rect* menu_rect;

int initMenu(){
    menu_rect = malloc(sizeof(SDL_Rect) * NB_RECT_MENU);
    
    if(menu_rect == NULL){
        perror("Cannot malloc menu_rect !");
        return -1;
    }
    
    return 0;
}

void dispMenu(SDL_Renderer* sdl_renderer){

    int window_width = 0;
    int window_height = 0;

    SDL_GetWindowSize(get_sdl_window(), &window_width, &window_height);
    // printf("Size : %d : %d \n", window_width, window_height);

    // Set render color
    SDL_SetRenderDrawColor(sdl_renderer, 10, 41, 80, 51);
    
    menu_rect[0].w = (int) window_width * 0.15;
    menu_rect[0].h = (int) window_width * 0.15;
    menu_rect[0].x = (int) (window_width / 2) - (menu_rect[0].w / 2);
    menu_rect[0].y = (int) window_height * 0.15;
    
    menu_rect[1].w = (int) window_width * 0.15;
    menu_rect[1].h = (int) window_width * 0.15;
    menu_rect[1].x = (int) menu_rect[0].x - menu_rect[1].w - (menu_rect[1].w * 0.75);
    menu_rect[1].y = (int) window_height * 0.15;

    menu_rect[2].w = (int) window_width * 0.15;
    menu_rect[2].h = (int) window_width * 0.15;
    menu_rect[2].x = (int) menu_rect[0].x + menu_rect[0].w + (menu_rect[2].w * 0.75) ;
    menu_rect[2].y = (int)window_height * 0.15;

    SDL_RenderFillRect(sdl_renderer, &menu_rect[1]);
    SDL_RenderFillRect(sdl_renderer, &menu_rect[0]);
    SDL_RenderFillRect(sdl_renderer, &menu_rect[2]);
    
    SDL_RenderPresent(get_sdl_rederer()); 
}

SDL_Rect* get_menu_rect(){
    return menu_rect;
}
