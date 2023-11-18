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

/* functions to write for Part B of lab */
void initialize_world_from_file(const char * filename) {
	
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

	
}
//void save_world_to_file(const char * filename) {
void save_world_to_file(char * worldstr) {
	static int i = 1;
	if(i == 10){
		i = 0; // avoid overflow of name_file regarding the incrmentation of i;
	}
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
	char name_file [15] = "./Save_world";  
	sprintf((name_file+12),"_%d",i); //./Save_world has 12 char
    fd = fopen(name_file,"w+");
    if(fd == NULL){
		perror("fd= NULL\n");
	}
	for(int y = 0 ; y <  worldWidth ; y ++){
		for(int x = 0 ; x < worldHeight ; x ++){
			if(world[x][y] == ALIVE){
				fprintf(fd,"|%c",CHAR_ALIVE); // print "|*" each time we found an alive cell
			}else{
				fprintf(fd,"|%c",CHAR_DEAD); // prin "| " each time we found a dead cell
			}
		}
		fprintf(fd,"|\n");
	}	
	close(fd);
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
