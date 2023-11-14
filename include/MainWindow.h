#ifndef _MAINWONDOW_H
#define _MAINWONDOW_H

#include <stdio.h>
#include <stdbool.h>
#include "Common.h"
#include "Graphics.h"
#include "MenuWindow.h"

int initSDLWindow();
SDL_Renderer* get_sdl_rederer();
SDL_Window* get_sdl_window();



#endif