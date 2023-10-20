#include "../SDL/include/SDL.h"
#include <stdio.h>
#include <stdbool.h>
#include "test.h"


int main(int argc, char* args[]) {
    // // Initialisation de SDL
    // if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    //     printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
    //     return 1;
    // }

    // // -- Tes d'affichage depuis un autre fichier



    // // Création de la fenêtre
    // SDL_Window* window = SDL_CreateWindow("Exemple SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    // if (window == NULL) {
    //     printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
    //     SDL_Quit();
    //     return 1;
    // }

    // // Boucle principale (affiche la fenêtre pendant quelques secondes)
    // bool quit = false;
    // SDL_Event e;

    // while (!quit) {
    //     while (SDL_PollEvent(&e) != 0) {
    //         if (e.type == SDL_QUIT) {
    //             quit = true;
    //         }
    //     }

    //     // Ici, vous pouvez ajouter du code pour dessiner quelque chose sur la fenêtre
    //     // (ceci est juste un exemple minimal)

    //     // Attendre pendant une courte période (en millisecondes)
    //     SDL_Delay(10000); // Attendre 10 seconde
    //     quit = true;     // Quitter la boucle
    // }

    // // Libération des ressources et fermeture de SDL
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    printf("Hello world !\n");
    return 0;
}
