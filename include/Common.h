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
#include <string.h>
#include <errno.h>
#include "MainWindow.h" // SDL graphic utilization
#include "Graphics.h"
#include "lifegame.h" // pre-implemented functions for Project Life
#include "lab1a.h" // Pre-declared functions for Project Life

typedef struct arguments_s{
    char* file_name;
};

extern int run_flag;
extern int worldHeight;
extern int worldWidth;

#endif