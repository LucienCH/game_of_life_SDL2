/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "../include/lifegame.h"
#include <stdlib.h>
#include <unistd.h>

/* add whatever other includes here */
#include <stdio.h>
#include "../include/lab1a.h"

extern int worldWidth;
extern int worldHeight;

/* number of generations to evolve the world */
// #define NUM_GENERATIONS 50 // Write in lab1a.h

// int main(void)
// {
// 	int n;

// 	/* TODO: initialize the world */


// 	for (n = 0; n < NUM_GENERATIONS; n++){
// 		next_generation();
// 		/* TODO (optional): Visualise world in each generation */
// 	}

// 	/* TODO: output final world state */


// 	return 0;
// }
void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules

	   Hint: use get_next_state(x,y) and set_next_state(x,y) */
		for(int x = 0 ; x < worldWidth ; x++){
			for(int y = 0 ; y < worldHeight ; y++){
				set_cell_state(x,y,get_next_state(x,y));
			}
		}

	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */
	int dead_or_alive = get_cell_state(x,y);
	if(dead_or_alive == DEAD ){
		if(num_neighbors(x,y) == 2 ){ //cells birth only and only if there is two cells alive around
			return ALIVE;
		}
	}else{
		if(2 <= num_neighbors(x,y) && num_neighbors(x,y) <= 3){ //cells die if more than 3 cells alive around ... 
		// ... or die if les than 2 cells around
			return ALIVE;
		}
	}
	return DEAD;
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE
	 
	   Use get_cell_state(x,y) */

		int nb_cell_alive = 0; // variable to count the number of cell alive
		int dead_or_alive = get_cell_state(x,y);
		for (int i = -1 ; i < 2; i ++){
			for(int j = -1 ; j < 2; j++){
				if(j != 0 || i != 0){
					if(get_cell_state(x+i,y+j) == ALIVE){
						nb_cell_alive ++;
						if( dead_or_alive == ALIVE && nb_cell_alive > 3 ){ //break loops if nb_neighbors > 3 (kills the cells)
							//break;
							goto endofnum_neighbors;
						}
					}	
				}
				
			}
		}
		endofnum_neighbors:
		//printf("nb_cell_alive =  %d \n",nb_cell_alive);
		/* 
			the number nb_cell_alive could be not true if the current cell is alive
			we broke the loops earlier to avoid useless checks

		*/
		return nb_cell_alive; 
}
