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

void save_world_to_file(const char * filename) {
	/* TODO: write the state of the world into a file with
	   name "filename". Assume the file can be created, or if
	   the file exists, overwrite the file. The ith character
	   of the jth line (zero-indexed) describes world[i][j]
	   using the characters CHAR_ALIVE and CHAR_DEAD

	   This file should be readable using the function
	   initialize_world_from_file(filename) above; we can use
	   it to resume a game later
	 */


}

/* you shouldn't need to edit anything below this line */

/* initializes the world to a hard-coded pattern, and resets
   all the cells in the next generation to DEAD */
void initialize_world(void) {
	int i, j;

	for (i = 0; i < WORLDWIDTH; i++)
		for (j = 0; j < WORLDHEIGHT; j++)
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
	for (int i = 0; i < WORLDWIDTH; i++)
		for (int j = 0; j < WORLDHEIGHT; j++)
			if (world[i][j] == ALIVE) return 0;
	return 1;
}

int get_world_width(void) {
	return WORLDWIDTH;
}

int get_world_height(void) {
	return WORLDHEIGHT;
}

int get_cell_state(int x, int y) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT)
		return DEAD;
	return world[x][y];
}

void set_cell_state(int x, int y, int state) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT) {
		fprintf(stderr,"Error: coordinates (%d,%d) are invalid.\n", x, y);
		abort();
	}
	nextstates[x][y] = state;
}

void finalize_evolution(void) {
	int x, y;
	for (x = 0; x < WORLDWIDTH; x++) {
		for (y = 0; y < WORLDHEIGHT; y++) {
			world[x][y] = nextstates[x][y];
			nextstates[x][y] = DEAD;
		}
	}
}

void output_world(void) {
	char worldstr[2*WORLDWIDTH+2];
	int i, j;

	worldstr[2*WORLDWIDTH+1] = '\0';
	// start the grid 
	worldstr[0] = '+'; //print + for the first column 
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-'; //print - from the first column to the last but one
	worldstr[2*WORLDWIDTH] = '+'; //print + for the last  column
	puts(worldstr);
	// print the content of the grid
	for (i = 0; i <= 2*WORLDWIDTH; i+=2)
		worldstr[i] = '|'; //create the skeleton of the grid by writing | each two cases
	for (i = 0; i < WORLDHEIGHT; i++) {
		for (j = 0; j < WORLDWIDTH; j++)
			worldstr[2*j+1] = world[j][i] == ALIVE ? CHAR_ALIVE : CHAR_DEAD; //each two cases, check the value in world and put 
			// the character regarding the state of the cell
			
		puts(worldstr);
	}
	// end of the grid 
	worldstr[0] = '+'; //print + for the first column 
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-'; //print - from the first column to the last but one
	worldstr[2*WORLDWIDTH] = '+'; //print + for the last  column
	puts(worldstr);
}