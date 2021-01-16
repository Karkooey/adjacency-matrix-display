/*
 * model.h
 *
 *  Created on: 9 Jan 2021
 *      Author: ClancyLight
 */

#ifndef MODEL_H_
#define MODEL_H_
#include <SDL2/SDL.h>


#define MODEL_NUM_NODES 8 // larger than 4x4 will require refactoring the Model.c for now

typedef struct{
	int x;
	int y;
}Dot_t;

int   model_adjMatrix[MODEL_NUM_NODES][MODEL_NUM_NODES];
int model_selectedNode;
int model_selectedNodePrevious;


SDL_Point   model_nodePos[MODEL_NUM_NODES];
Dot_t model_mouseDot;


void model_update();
void model_init();
void model_wasClickedHere(int mouseX, int mouseY, int set);
void model_setNodePositions();
void model_connectNodes();
void model_moveNode(int nodeIndex, int mouseX, int mouseY);

#endif /* MODEL_H_ */
