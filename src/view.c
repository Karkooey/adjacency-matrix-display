/*
 * view.c
 *
 *  Created on: 9 Jan 2021
 *      Author: ClancyLight
 */

#include "../inc/view.h"
#include "../inc/main.h"
#include <SDL2/SDL.h>



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

static void drawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

static void render_adjacencyMatrix(){

	SDL_SetRenderDrawColor(windowRend.renderer, YELLOW_R, YELLOW_G, YELLOW_B, 255);
	for(int i = 0; i < MODEL_NUM_NODES; i++){
		for(int j = 0; j < MODEL_NUM_NODES; j++){
			drawCircle(windowRend.renderer,
					i*VIEW_ADJMATRIX_SPACING + VIEW_ADJMATRIX_OFFSET, // model_dot.x
					j*VIEW_ADJMATRIX_SPACING + VIEW_ADJMATRIX_OFFSET,// model_dot.y
					VIEW_ADJMATRIX_RADIUS
					);
			if(model_adjMatrix[i][j] == 1){
				for(int r = VIEW_ADJMATRIX_RADIUS; r > 1; r--)
					drawCircle(windowRend.renderer,
							i*VIEW_ADJMATRIX_SPACING + VIEW_ADJMATRIX_OFFSET,
							j*VIEW_ADJMATRIX_SPACING + VIEW_ADJMATRIX_OFFSET,
							r
							);
			}
		}
	}
}

static void render_nodes(){

	for(int node = 0; node < MODEL_NUM_NODES; node++){
		//TODO: give each node an x and y co-ordinate and draw. Currently only 4x4
		if(node == model_selectedNodePrevious || node == model_selectedNode){
			SDL_SetRenderDrawColor(windowRend.renderer, 255, 255, 255, 255);
		}else{
			SDL_SetRenderDrawColor(windowRend.renderer, RED_R, RED_G, RED_B, 255);
		}
		drawCircle(windowRend.renderer, model_nodePos[node].x, model_nodePos[node].y, VIEW_GRAPH_CIRCLESIZE);

	}
}

static void render_graph(){
	SDL_SetRenderDrawColor(windowRend.renderer, RED_R, RED_G, RED_B, 255);

	render_nodes();

	// Connecting the nodes with lines
	for(int i = 0; i < MODEL_NUM_NODES; i++){
		for(int j = 0; j < MODEL_NUM_NODES; j++){
			if(model_adjMatrix[i][j] == 1){
				if(i == j){
					drawCircle(windowRend.renderer, model_nodePos[i].x, model_nodePos[i].y, VIEW_GRAPH_CIRCLESIZE - 3);
				}else{
					SDL_RenderDrawLine(windowRend.renderer, model_nodePos[i].x, model_nodePos[i].y, model_nodePos[j].x, model_nodePos[j].y);
				}
			}
		}
	}
}

void render_clickedasCircle(){
	SDL_SetRenderDrawColor(windowRend.renderer, 255, 255, 255, 255);

	drawCircle(windowRend.renderer, model_mouseDot.x, model_mouseDot.y, VIEW_MOUSECIRCLE_SIZE);
}

void render_graphBorder(){
		SDL_RenderDrawLine(windowRend.renderer, VIEW_MARGINLEFT - 20, VIEW_MARGINLEFT- 20, VIEW_MARGINLEFT- 20, WINDOW_HEIGHT);
		SDL_RenderDrawLine(windowRend.renderer, VIEW_MARGINLEFT - 20, VIEW_MARGINLEFT- 20, WINDOW_WIDTH, VIEW_MARGINLEFT- 20);
}

void view_render(void){
	SDL_SetRenderDrawColor(windowRend.renderer, 0, 0, 0, 255);
	SDL_RenderClear(windowRend.renderer);

	render_adjacencyMatrix();
	render_graphBorder();
	render_graph();
	render_clickedasCircle();

	SDL_RenderPresent(windowRend.renderer);
}

void view_destroyWindow(void) {
	SDL_DestroyRenderer(windowRend.renderer);
	SDL_DestroyWindow(windowRend.window);
	SDL_Quit();
}
