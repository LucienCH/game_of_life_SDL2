#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "MainWindow.h"
#include "Graphics.h"
#include "Common.h"
#include "../include/lifegame.h"
#include "../include/lab1a.h"
#include <time.h>


int main(int argc, char* args[]){

    // pthread_t* t_sdl;

<<<<<<< HEAD
    // if (SDL_Init(SDL_INIT_VIDEO) != 0){
    //     printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
    //     exit(EXIT_FAILURE);
    // }
<<<<<<< HEAD

    // pthread_create(t_sdl, NULL,(void*)initSDLWindow,NULL);

    // pthread_join(t_sdl, NULL);
    
   // initSDLWindow();
   printf("Hello Olivia !\n");
=======
       // pthread_create(t_sdl, NULL,(void*)initSDLWindow,NULL);

    // pthread_join(t_sdl, NULL);
    
    // initSDLWindow();
=======
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    initSDLWindow();

    init_matrix(600, 300);
>>>>>>> origin/lucien

    initialize_world();
    
    for(int i = 0; i < NUM_GENERATIONS; i++)
    {
        next_generation();
        system("clear");
        output_world();    
        usleep(100000); // 100 000 micro seconde = 0,1 seconde
    }
>>>>>>> origin/Antoine

    return 0;
}
