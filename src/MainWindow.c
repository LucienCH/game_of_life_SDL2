#include "MainWindow.h"
#include "Common.h"

SDL_Window* sdl_window;
SDL_Renderer* sdl_renderer;

void initSDLWindow(){

    sdl_window = SDL_CreateWindow("Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);

    // Setup renderer
    sdl_renderer =  SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);

    // Clear winow
    SDL_RenderClear(sdl_renderer);

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

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


        // Set render color to blue ( rect will be rendered in this color )
        SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255 );

        // Render rect
        SDL_RenderFillRect(sdl_renderer, &r );

        // Render the rect to the screen
        SDL_RenderPresent(sdl_renderer);


        // // Attendre pendant une courte période (en millisecondes)
        // SDL_Delay(10000); // Attendre 10 seconde
        // quit = true;     // Quitter la boucle
    }

    // Libération des ressources et fermeture de SDL
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}
