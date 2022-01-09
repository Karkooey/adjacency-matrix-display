/*
 * main.c
 *
 *  Created on: 9 Jan 2021
 *      Author: ClancyLight
 */
//#include "../inc/main.h"
#include <stdio.h>
#include <SDL2/SDL.h>

#define FALSE 0
#define TRUE  1
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800




static Window_t windowRend = {NULL, NULL};

int view_initializeWindow(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Error initializing SDL.\n");
		return FALSE;
	}
	windowRend.window = SDL_CreateWindow(
		"The Game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		0
	);
	if (!windowRend.window) {
		fprintf(stderr, "Error creating SDL Window.\n");
		return FALSE;
	}
	windowRend.renderer = SDL_CreateRenderer(windowRend.window, -1, SDL_RENDERER_ACCELERATED);// try this later: SDL_RENDERER_ACCELERATED
	if (!windowRend.renderer) {
		fprintf(stderr, "Error Creating SDL Renderer.\n");
		return FALSE;
	}
	return TRUE;
}



int main(int argc, char* argv[]){
	//ctrl_initAll();

	/*while(ctrl_getWantQuit()){

		ctrl_processInput();
		model_update();
		view_render();
		SDL_Delay(50);
	}
	view_destroyWindow();
	return 0;
}
*/
	//testSDLEnvironment();
	SDL_Delay(3000);
	return 0;
	
	}
