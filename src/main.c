#include "MainWindow.h"
#include "Graphics.h"
#include "Common.h"
#include "lifegame.h"
#include "lab1a.h"

int main(int argc, char* args[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_VideoInit(SDL_GetVideoDriver(0));
    
    // initSDLWindow();
    // init_matrix(600, 300);

    printf("Testing video drivers...\n");
    int nbDrive = SDL_GetNumVideoDrivers();

    for( int i = 0; i < nbDrive; ++i )
    {
       printf("Drv %d : %s\n", i,SDL_GetVideoDriver(i));
    }

    printf("\nDrv used %s \n", SDL_GetCurrentVideoDriver());



    // initialize_world();
    
    
    // for(int i = 0; i < NUM_GENERATIONS; i++)
    // {
    //     next_generation();
    //     system("clear");
    //     output_world();    
    //     usleep(100000); // 100 000 micro seconde = 0,1 seconde
    // }

    return 0;
}
