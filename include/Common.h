#ifndef _COMMON_H
#define _COMMON_H

/*
 * File config for Project Life
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h> // file library
#include "SDL/include/SDL.h"
#include <pthread.h> // multi-thread utlization (main.c)
#include "MainWindow.h" // SDL graphic utilization
#include "lifegame.h" // pre-implemented functions for Project Life
#include "lab1a.h" // Pre-declared functions for Project Life

typedef struct{
    int arg1;
    int arg2;
}arguments_t;


#endif