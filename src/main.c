#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "MainWindow.h"
#include "Common.h"
#include "../include/lifegame.h"
#include "../include/lab1a.h"
#include <time.h>

extern int  num_generation;
int main(int argc, char* args[]){

    pthread_t* t_sdl;

    // if (SDL_Init(SDL_INIT_VIDEO) != 0){
    //     printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
    //     exit(EXIT_FAILURE);
    // }
       // pthread_create(t_sdl, NULL,(void*)initSDLWindow,NULL);

    // pthread_join(t_sdl, NULL);
    
    // initSDLWindow();


    initialize_world_from_file("Save_world");
    //initialize_world(TAILLE_100);
    // initialize_world();
    // initialize_world();
    getchar();
    for(int i = 0; i < 50; i++)
    {
        next_generation();
        system("clear");
        output_world();    
        usleep(100000); // 100 000 micro seconde = 0,1 seconde
    }
    save_world_to_file("./Save_world_2");
    return 0;
}

void * thread_initialize_world(void* arg){
   
    next_generation(); // à modifier / completer ...

}
