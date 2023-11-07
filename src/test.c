#include <stdio.h>
#include <stdlib.h>

void mySuperFonction(void){
    printf("Hello world from mySuperFonction\n");
}



void AfficherMatrice(void){
    char tab1[10][10];

    for (int i=0; i<10; i++){
        
        for (int j=0; j<10; j++){
            tab1[i][j] = '*';
        }
    }

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            printf("%c ",tab1[i][j]);
        }
        printf("\n");
    }

    
}


void creerMatrice(void){
    int nbr = 0;
    printf("choisir le nbr de case : ");
    scanf("%d", &nbr);
    char* tab2;

    tab2 = malloc(sizeof(char)*nbr);
    if (tab2 == NULL){
        printf("erreur\n");
        exit(EXIT_FAILURE);
    } 
    for (int i=0; i<nbr; i++){
        tab2[i] = '*';
    }

    for (int i=0; i<nbr; i++){
        printf("%c ",tab2[i]);
    }
    printf("\n");
    free(tab2);
}

