/*
 * view.h
 *
 *  Created on: 9 Jan 2021
 *      Author: ClancyLight
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "SDL2/SDL.h"

typedef struct {
	SDL_Window*   window;
	SDL_Renderer* renderer;
}Window_t;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

#define PURPLE_R 33
#define PURPLE_G 23
#define PURPLE_B 74

#define GREEN_R 20
#define GREEN_G 99
#define GREEN_B 110

#define YELLOW_R 247
#define YELLOW_G 189
#define YELLOW_B 15

#define RED_R 212
#define RED_G 0
#define RED_B 80

#define VIEW_ADJMATRIX_RADIUS 10
#define VIEW_ADJMATRIX_OFFSET 30
#define VIEW_ADJMATRIX_SPACING 20
#define VIEW_MOUSECIRCLE_SIZE 5
#define VIEW_GRAPH_CIRCLESIZE 15

#define VIEW_MARGINLEFT  200
#define VIEW_MARGINRIGHT 50


int view_initializeWindow(void);
void view_render(void);
void view_destroyWindow(void);


#endif /* VIEW_H_ */
