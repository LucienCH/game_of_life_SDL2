#include <pthread.h>
#include "Common.h"
#include "MainWindow.h"
#include "Graphics.h"
#include "lifegame.h"


int main(int argc, char* args[]){

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    if(initSDLWindow() != 0){
        perror("Cannot init SDL_Window ...");
        return -1;
    }

    return 0;
}
