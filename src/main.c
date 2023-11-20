#include "Common.h"

extern int  num_generation;

void* thread_initialize_world(void* arg){

    initialize_world_from_file("./gun_50");
    //initialize_world(TAILLE_100);
    for(int i = 0; i < 250; i++)
    {
        next_generation();
        system("clear");
        output_world();    
        usleep(100000); // 100 000 micro seconde = 0,1 seconde
    }
    save_world_to_file("./gun_50_add_250");
   
    next_generation(); // à modifier / completer ...

}


int main(int argc, char* args[]){

    pthread_t t_game;

    pthread_create(&t_game, NULL, thread_initialize_world, NULL);

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    if(initSDLWindow() != 0){
        perror("Cannot init SDL_Window ...");
        return -1;
    }
    
    pthread_join(t_game, NULL);
    
   
    return 0;
}
