#include "Common.h"

unsigned long long  num_generation;

int run_flag = 1;
int worldHeight = 150;
int worldWidth = 150;

void* thread_initialize_world(void* arg){
    char save[3];

    //initialize_world_from_file( ((struct arguments_s*)arg)->file_name );
    //initialize_world(TAILLE_100);
    system("clear");
    printf("Fermer la fenetre SDL pour finir le jeu\n");
    
    while(run_flag){
        printf("\rNombre de generations : %llu", num_generation);
        fflush(stdout);
        next_generation();
        usleep(100000); // 0.05 secondes;
        num_generation++;
    }
    printf("\n");
    printf("\t\t ======== FIN DU JEU ========\n\n");
    printf("Voulez vous sauvegarder (oui | non) : ");
    scanf("%s", save);
    
    if(strcmp("oui", save) == 0){
        char* save_name = malloc(sizeof(char) * 148); // 128 char + 20 char
        char num_gen_txt[20];
        if(!save_name){
            perror("Malloc failed ");
            exit(EXIT_FAILURE);
        }
        
        do{
            if( (strcmp("\n", save_name) == 0) ){
                printf("Erreur de saisie veuillez saisir un chemin/nom de fichier valide !\n");
            }
            printf("Saisir le chemin/nom de la sauvegarde : ");
            scanf("%s", save_name);

        }while ((strcmp("\n", save_name) == 0) || (strcmp("\0", save_name) == 0));
        snprintf(num_gen_txt, 25,"_add_%llu", num_generation);
        strcat(save_name, num_gen_txt);
        save_world_to_file(save_name);
    }else if(strcmp("non", save) == 0){
        printf("Pas de sauvegarde effectue.\n");
        printf("Fermeture du programme...\n");
    }

}

int grid_size_user(){
    int size = 0;
    int ch;
    int nbytes = 0;
    
    printf("Selectioner la taille de la grille\n\n");
    printf("1 -- 50x50 \n");
    printf("2 -- 100x100 \n");
    printf("3 -- 150x150\n");

    printf("Choix : ");
    nbytes = scanf("%d", &size);

    if(nbytes == 0){
        printf("Pas un entier ! \n");
        do {
            ch = getchar();
        } while ((ch != EOF) && (ch != '\n'));
    }
    
    if( size < 1 || size > 3){
        printf("Choix impossible ! \n");
        return -1;
    }else{
        return size;
    }
}

int grid_select_user(){

    int choice = 0;
    int nbytes = 0;
    int ch;

    printf("Selectioner le type de grille à utiliser\n\n");
    printf("1 -- aléatoir\n");
    printf("2 -- fichier de preset\n");
    
    printf("Votre choix : ");
    nbytes = scanf("%d", &choice);
    
    if(nbytes == 0){
        printf("Pas un entier ! \n");
        do {
            ch = getchar();
        } while ((ch != EOF) && (ch != '\n'));
    }
    
    if(choice < 1 || choice > 2){
        printf("Choix impossible ! \n");
        return -1;
    }else{
        return choice;
    }
}


int main(int argc, char* args[]){
    char* file_name;
    int size = -1;
    int choice = -1;
    int wSize = 0;
    pthread_t t_game;

    struct arguments_s* arg_struct = (struct arguments_s*) malloc(sizeof(struct arguments_s*));

    arg_struct->file_name = malloc(sizeof(char) * 128);

    if(!arg_struct->file_name){
        perror("Cannot malloc ");
        exit(EXIT_FAILURE);
    }

    // -------------- INIT MENU --------------------
    system("clear");
    printf("\t\t ======== JEU DE LA VIE ========\n\n");

    
    while(choice == -1){
        choice = grid_select_user();
    }

    while(size == -1){
        size = grid_size_user();
        //printf("Size : %d\n", size);
    }

    if(choice == 1){
        random_grid();
    }else{
        printf("Saisir le chemin/nom du fichier preset \n");
        printf("Exemple (./Preset_4_gun , ./Preset_2_stable , ./Preset_1_osci ... ) : ");
        scanf("%s", arg_struct->file_name);
        initialize_world_from_file( arg_struct->file_name );
    }

    switch(size){
            case 1: 
                worldHeight = 50;
                worldWidth = 50;
                wSize = 250;
                break;
            case 2:
                worldHeight = 100;
                worldWidth = 100;
                wSize = 500;
                break;
            case 3:
                worldHeight = 150;
                worldWidth = 150;
                wSize = 750;
                break;
            default:
                printf("Valeur incorrecte ..."); 
                exit(EXIT_FAILURE);
    }

    printf("Fichier selectionne : %s\n", arg_struct->file_name);

    pthread_create(&t_game, NULL, thread_initialize_world, (void*) arg_struct);

    run_flag = 1;

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    if(initSDLWindow(wSize) != 0){
        perror("Cannot init SDL_Window ...");
        return -1;
    }
    
    pthread_join(t_game, NULL);
   
    return 0;
}
