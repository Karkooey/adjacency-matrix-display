/*
 * main.c
 *
 *  Created on: 9 Jan 2021
 *      Author: ClancyLight
 */
#include "../inc/main.h"
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
	ctrl_initAll();

	while(ctrl_getWantQuit()){

		ctrl_processInput();
		model_update();
		view_render();
		SDL_Delay(50);
	}
	view_destroyWindow();
	return 0;
}
