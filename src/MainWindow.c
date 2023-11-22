#include "Common.h"


SDL_Window* sdl_window;
SDL_Renderer* sdl_renderer;

int initSDLWindow(int wSize){

    sdl_window = SDL_CreateWindow("Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,wSize,wSize,SDL_WINDOW_SHOWN);

    // Setup renderer
    sdl_renderer =  SDL_CreateRenderer(sdl_window, -1,SDL_RENDERER_SOFTWARE);
    

    // Boucle principale (affiche la fenêtre pendant quelques secondes)
    bool quit = false;
    SDL_Event e;

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);

    // Clear winow
    SDL_RenderClear(sdl_renderer);

    initMatrix(0, 0);
    SDL_RenderPresent(get_sdl_rederer());


    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }
        usleep(16000);
        change_grid_state();
    }

    // Libération des ressources et fermeture de SDL
    freeSDLRect();
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    run_flag = 0;
    return 0;
}


SDL_Renderer* get_sdl_rederer(){
    return sdl_renderer;
}

SDL_Window* get_sdl_window(){
    return sdl_window;
}