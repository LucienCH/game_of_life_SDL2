#include <stdio.h>
#include <pthread.h>

#include "MainWindow.h"
#include "Graphics.h"
#include "Common.h"
#include "../include/lifegame.h"


int main(int argc, char* args[]){

    // pthread_t* t_sdl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    initSDLWindow();

    init_matrix(600, 300);

    return 0;
}
