/*
 * model.c
 *
 *  Created on: 11 Jan 2021
 *      Author: ClancyLight
 */

#include "../inc/model.h"
#include "../inc/view.h"
#include <stdlib.h>
#include <time.h>

extern int model_adjMatrix[MODEL_NUM_NODES][MODEL_NUM_NODES];
extern SDL_Point   model_nodePos[MODEL_NUM_NODES];
extern Dot_t model_mouseDot;

extern int model_selectedNodePrevious;
extern int model_selectedNode;

void model_setNodePositions(){
	if(MODEL_NUM_NODES < 5){
		for(int node = 0; node < MODEL_NUM_NODES; node++){
			//TODO: give each node an x and y co-ordinate and draw. Currently only 4x4
			model_nodePos[node].x = (node % 2)*100 + 200;
			model_nodePos[node].y = (node < 2 ? 0 : 1)*100 + 200;
		}
	}else{
		//TODO: larger than 5x5 matrices
		struct timespec  t;
		clock_gettime(CLOCK_REALTIME, &t);
		srand(t.tv_nsec);

		for(int node = 0; node < MODEL_NUM_NODES; node++){
			model_nodePos[node].x = (rand() % (WINDOW_WIDTH - (VIEW_MARGINLEFT + VIEW_MARGINRIGHT)) + VIEW_MARGINLEFT);
			model_nodePos[node].y = (rand() % (WINDOW_HEIGHT -(VIEW_MARGINLEFT + VIEW_MARGINRIGHT)) + VIEW_MARGINLEFT);
		}

	}
}

void model_moveNode(int nodeIndex, int mouseX, int mouseY){

	model_nodePos[nodeIndex].x = mouseX;
	model_nodePos[nodeIndex].y = mouseY;
}

void fillGraphWithIntValue(int fillVal){
	for(int j = 0; j < MODEL_NUM_NODES; j++){
		for(int i = 0; i < MODEL_NUM_NODES; i++){
			model_adjMatrix[i][j] = fillVal;
		}
	}
}
void model_connectNodes(){
	model_adjMatrix[model_selectedNode][model_selectedNodePrevious] = 1;
	model_adjMatrix[model_selectedNodePrevious][model_selectedNode] = 1;
}

void nodeSelected(int index){
	model_selectedNode = index;

	if(model_selectedNode != -1 && model_selectedNodePrevious != -1){
		model_connectNodes();
		model_selectedNode = -1;
		model_selectedNodePrevious = -1;
	}else {
		model_selectedNodePrevious = model_selectedNode;
	}
	printf("selectedNode: %d\n", model_selectedNode);
}

void model_wasClickedHere(int mouseX, int mouseY, int set){
	model_mouseDot.x = mouseX;
	model_mouseDot.y = mouseY;
	//	printf("mouseX: %d, mouseY: %d\n", mouseX, mouseY);

	int min = VIEW_ADJMATRIX_OFFSET - VIEW_ADJMATRIX_RADIUS;
	int di = VIEW_ADJMATRIX_RADIUS * 2;



	if(mouseX <= VIEW_MARGINLEFT && mouseY <= VIEW_MARGINLEFT){
		model_adjMatrix[(int)((mouseX - min)/di)][(int)((mouseY - min)/di)] = set;
		model_adjMatrix[(int)((mouseY - min)/di)][(int)((mouseX - min)/di)] = set;
	}else if (set == 1){

		for(int i = 0; i < MODEL_NUM_NODES; i++){
			int x = abs(mouseX - model_nodePos[i].x);
			int y = abs(mouseY - model_nodePos[i].y);
			if(x <= VIEW_ADJMATRIX_RADIUS && y <= VIEW_ADJMATRIX_RADIUS){
				nodeSelected(i);
			}
		}
		if (model_selectedNode != -1){
				model_moveNode(model_selectedNode, mouseX, mouseY);
		}
	}else if (set == 0){
		nodeSelected(-1);
		nodeSelected(-1);
	}
}

void fillGraphManually5by5(){
	int m[5][5] =
	{	//   A B C D E
			{0,0,0,0,0},//A
			{0,0,0,0,0},//B
			{0,0,0,0,0},//C
			{0,0,0,0,0},//D
			{0,0,0,0,0} //E
	};

	for(int j = 0; j < MODEL_NUM_NODES; j++){
		for(int i = 0; i < MODEL_NUM_NODES; i++){
			model_adjMatrix[i][j] = m[i][j];
		}
	}

}

void model_init(){
//	fillGraphWithIntValue(0);
	fillGraphManually5by5();

	model_mouseDot.x = 0;
	model_mouseDot.y = 0;
	model_setNodePositions();
	model_selectedNodePrevious = -1;
	model_selectedNode = -1;
}

void model_update(){


}
