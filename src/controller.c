/*
 * controller.c
 *
 *  Created on: 9 Jan 2021
 *      Author: ClancyLight
 */

#include "../inc/controller.h"
#include "../inc/main.h"
#include "SDL2/SDL.h"


static int wantQuit;

void ctrl_setWantPlay(){ wantQuit = TRUE;}

int ctrl_getWantQuit(){
	return wantQuit;
}

void ctrl_initAll(){
	wantQuit = view_initializeWindow();
	ctrl_setWantPlay();
	model_init();
}

void ctrl_processInput() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		wantQuit = FALSE;
		break;
	case SDL_KEYDOWN:
		if(event.key.keysym.sym == SDLK_ESCAPE)
			wantQuit = FALSE;
		if(event.key.keysym.sym == SDLK_SPACE)
			model_setNodePositions();
		break;
	case SDL_KEYUP:
		break;
	case SDL_MOUSEBUTTONDOWN:
		if(event.button.button == SDL_BUTTON_LEFT)
			model_wasClickedHere((int)event.button.x,(int)event.button.y, 1);
		if(event.button.button == SDL_BUTTON_RIGHT)
			model_wasClickedHere((int)event.button.x,(int)event.button.y, 0);
		break;
	case SDL_MOUSEBUTTONUP:
		if(event.button.button == SDL_BUTTON_LEFT)
			//
		break;
	}
}
