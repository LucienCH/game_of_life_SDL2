#include <stdio.h>
#include <stdbool.h>
#include "test.h"
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_config.h"



int main(int argc, char* args[]) {

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

    // -- Tes d'affichage depuis un autre fichier

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Exemple SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* sdl_rend = SDL_CreateRenderer(window,0,0);
    
    if(sdl_rend == NULL){
        printf("Erreur SDL renderer ...");
        SDL_Quit();
        return -1;
    }

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
        SDL_SetRenderDrawColor( sdl_rend, 255, 255, 255, 255 );

        // Clear winow
        SDL_RenderClear(sdl_rend);


        // Set render color to blue ( rect will be rendered in this color )
        SDL_SetRenderDrawColor( sdl_rend, 0, 0, 0, 255 );

        // Render rect
        SDL_RenderFillRect( sdl_rend, &r );

        // Render the rect to the screen
        SDL_RenderPresent(sdl_rend);


        // // Attendre pendant une courte période (en millisecondes)
        // SDL_Delay(10000); // Attendre 10 seconde
        // quit = true;     // Quitter la boucle
    }

    // Libération des ressources et fermeture de SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
