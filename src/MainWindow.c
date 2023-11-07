#include "MainWindow.h"
#include "Common.h"
#include "Graphics.h"

SDL_Window* sdl_window;
SDL_Renderer* sdl_renderer;

void initSDLWindow(){

    sdl_window = SDL_CreateWindow("Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,720,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    // Setup renderer
    sdl_renderer =  SDL_CreateRenderer(sdl_window, -1, 0);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);

    // Clear winow
    SDL_RenderClear(sdl_renderer);

    // // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    // SDL_Rect r;
    // r.x = 10;
    // r.y = 10;
    // r.w = 10;
    // r.h = 10;

    // Boucle principale (affiche la fenêtre pendant quelques secondes)
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        // Ici, vous pouvez ajouter du code pour dessiner quelque chose sur la fenêtre
        // (ceci est juste un exemple minimal)

        // Set render color to red ( background will be rendered in this color )
        SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255 );

        // Clear winow
        SDL_RenderClear(sdl_renderer);

        init_matrix(640,480);


        

        // // Attendre pendant une courte période (en millisecondes)
        // SDL_Delay(10000); // Attendre 10 seconde
        // quit = true;     // Quitter la boucle
    }

    // Libération des ressources et fermeture de SDL
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

SDL_Renderer* get_sdl_rederer(){
    return sdl_renderer;
}

SDL_Window* get_sdl_window(){
    return sdl_window;
}