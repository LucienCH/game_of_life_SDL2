/*
 * lifegame.c
 *
 *  Created on:
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/lifegame.h"

/* hard-coded world size */
// hard-coded value in lifegame.h

/* character representations of cell states */
#define CHAR_ALIVE '*'
#define CHAR_DEAD ' '

int worldWidth = 0;
int worldHeight = 0;
int num_generation =0;

/* current cell states of the world */
static int world[WORLDWIDTH][WORLDHEIGHT];

/* next generation cell states */
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

/*----------- Antoine modifications ----------- */

/* Get the world for other source files */
int*** get_the_world(void){
	return &world; 
}

/*----------- Antoine modifications ----------- */
/* Generate Grid_null preset
 */
void grid_null(void){
		worldHeight = 250;
		worldWidth = 250;
		num_generation = 500;
	for (int x = 0; x < worldWidth; x++) {
		for (int y = 0; y < worldHeight; y++) {
			world[x][y] = DEAD;
		} 
	}
	save_world_to_file("./Grid_null_250");
}

/* functions to write for Part B of lab */
void initialize_world_from_file(char * name_file) {
	/* TODO: read the state of the world from a file with
	   name "filename". Assume file exists, is readable, and
	   the ith character of the jth line (zero-indexed) describes
	   world[i][j] according to the characters CHAR_ALIVE and
	   CHAR_DEAD

	   Assume a line does not contain more than 256 characters
	   (including newline). If a line doesn't contain WORLDWIDTH
	   characters, remaining cells in line are presumed DEAD.
	   Similarly, if the file does not contain WORLDHEIGHT lines,
	   remaining lines are presumed dead.

	   On error, print some useful error message and call abort().

	   Also need to reset the next generation to DEAD
	 */
	
	char * rcv_frm_file = (char *) malloc(sizeof(char));
	FILE *fd;
	fd = fopen(name_file,"r+");	
	    if(fd == NULL){
		perror("fd= NULL can't open file \n");
		exit(-1);
	}
	for(int y = 0 ; y < WORLDHEIGHT  ; y ++){
		int j = 0;
		for(int x = 0 ; x < WORLDWIDTH*2 ; x ++){
			if(fscanf(fd,"%c",rcv_frm_file) != EOF){

			printf("%c",(*rcv_frm_file));
			if(*rcv_frm_file == '|' ){
				;
			}else if(*rcv_frm_file == '\n' ){
				worldWidth = x/2; //because the real grid doesn't contain "|" characteres
				break;
			}else if(*rcv_frm_file == CHAR_ALIVE){
				world[j][y] = ALIVE; 
				j++;
			}else{
				world[j][y] = DEAD;
				j++;
			}
			}else{
				perror("end file");
				break;
			}
		}

		fscanf(fd,"%c",rcv_frm_file);
		lseek(fd,-1,SEEK_CUR); //actuellement inutile (ne marche pas)
		if(*rcv_frm_file == '\n' ){
		 	worldHeight = y+1; // because worldHeight is the size of the grid, not the index
		 	break;
		}
	}	
	free(rcv_frm_file);
	fclose(fd);
	if(is_World_Empty()){
		perror("Read File Failled\n");
	}
	// Intitialize the next generation to DEAD
	for (int x = 0; x < worldWidth; x++) {
		for (int y = 0; y < worldHeight; y++) {
			nextstates[x][y] = DEAD;
		} 
	}
	return;
}

void save_world_to_file(char * name_file) {
	/* TODO: write the state of the world into a file with
	   name "filename". Assume the file can be created, or if
	   the file exists, overwrite the file. The ith character
	   of the jth line (zero-indexed) describes world[i][j]
	   using the characters CHAR_ALIVE and CHAR_DEAD

	   This file should be readable using the function
	   initialize_world_from_file(filename) above; we can use
	   it to resume a game later
	 */	
	FILE *fd;
	fd = fopen(name_file,"w+");
    if(fd == NULL){
		perror("fd= NULL can't open file \n");
	}
	for(int y = 0 ; y <  worldHeight ; y ++){
		for(int x = 0 ; x < worldWidth ; x ++){
			if(world[x][y] == ALIVE){
				fprintf(fd,"|%c",CHAR_ALIVE); // print "|*" each time we found an alive cell
			}else{
				fprintf(fd,"|%c",CHAR_DEAD); // prin "| " each time we found a dead cell
			}
		}
		fprintf(fd,"|\n");
	}
	fprintf(fd,"\n");
	fclose(fd);
}

/* you shouldn't need to edit anything below this line */

/* initializes the world to a hard-coded pattern, and resets
   all the cells in the next generation to DEAD */
void initialize_world(SIZE_MONDE Taille) {
	int i, j;

	switch (Taille)
	{
	case TAILLE_10:
		worldHeight = 10;
		worldWidth = 10;
		num_generation = 50;
		break;
	case TAILLE_100:
		worldHeight = 50;
		worldWidth = 50;
		num_generation = 500;
		break;
	case TAILLE_500:
		worldHeight = 500;
		worldWidth = 500;
		num_generation = 2500;
		break;
	default:
		perror("--- Value for the world incompatble\n"); //shouldn't be another value
		break;
	}

	for (i = 0; i < worldWidth; i++)
		for (j = 0; j < worldHeight; j++)
			world[i][j] = nextstates[i][j] = DEAD;
	/* pattern "glider" */
	world[1][2] = ALIVE;
	world[3][1] = ALIVE;
	world[3][2] = ALIVE;
	world[3][3] = ALIVE;
	world[2][3] = ALIVE;

// 	world[2][2] = ALIVE;//haut-gauche
// 	world[3][2] = ALIVE;//haut-centre
//	world[4][2] = ALIVE;//haut-droite

// 	world[2][3] = ALIVE;//centre gauche
// 	world[3][3] = ALIVE;//centre 
// 	world[4][3] = ALIVE;//centre droit
	
// 	world[2][4] = ALIVE;//bas-gauche
// 	world[3][4] = ALIVE;//bas-centre
// 	world[4][4] = ALIVE;//bas-droite
}

int is_World_Empty(void) {
	for (int i = 0; i < worldWidth; i++)
		for (int j = 0; j < worldHeight; j++)
			if (world[i][j] == ALIVE) return 0;
	return 1;
}

int get_world_width(void) {
	return worldWidth;
}

int get_world_height(void) {
	return worldHeight;
}

int get_cell_state(int x, int y) {
	if (x < 0 || x >= worldWidth || y < 0 || y >= worldWidth)
		return DEAD;
	return world[x][y];
}

void set_cell_state(int x, int y, int state) {
	if (x < 0 || x >= worldWidth || y < 0 || y >= worldHeight) {
		fprintf(stderr,"Error: coordinates (%d,%d) are invalid.\n", x, y);
		abort();
	}
	nextstates[x][y] = state;
}

void finalize_evolution(void) {
	int x, y;
	for (x = 0; x < worldWidth; x++) {
		for (y = 0; y < worldHeight; y++) {
			world[x][y] = nextstates[x][y];
			nextstates[x][y] = DEAD;
		} 
	}
}

void output_world(void) {
	char worldstr[2*worldWidth+2];
	int i, j;

	worldstr[2*worldWidth+1] = '\0';
	// start the grid 
	worldstr[0] = '+'; //print + for the first column 
	for (i = 1; i < 2*worldWidth; i++)
		worldstr[i] = '-'; //print - from the first column to the last but one
	worldstr[2*worldWidth] = '+'; //print + for the last  column
	puts(worldstr);
	// print the content of the grid
	for (i = 0; i <= 2*worldWidth; i+=2)
		worldstr[i] = '|'; //create the skeleton of the grid by writing | each two cases
	for (i = 0; i < worldHeight; i++) {
		for (j = 0; j < worldWidth; j++)
			worldstr[2*j+1] = world[j][i] == ALIVE ? CHAR_ALIVE : CHAR_DEAD; //each two cases, check the value in world and put 
			// the character regarding the state of the cell
			
	puts(worldstr);		
	}
	// end of the grid 
	worldstr[0] = '+'; //print + for the first column 
	for (i = 1; i < 2*worldWidth; i++)
		worldstr[i] = '-'; //print - from the first column to the last but one
	worldstr[2*worldWidth] = '+'; //print + for the last  column
	puts(worldstr);
}
