#include "Problem.h"

Problem::Problem(vector<int> startVector, int heurOption) {
	this->init = new Node(startVector,heurOption);

	vector<int> goalVector(9,0);
	for(int i = 0; i < 8; i++) goalVector[i]=i+1;
	this->goal = new Node(goalVector,heurOption);
	move.push_back({0,1});
	move.push_back({0,-1});
	move.push_back({1,0});
	move.push_back({-1,0});
}

void Problem::findNeighbors(Node* curr) {

}

void Problem::calcNext(Node* curr) {
	int zero = -1;
	for(int i = 0; i < 9; i++) {
		if(curr->board[i]==0) {
			zero=i;
			break;
		}
	}
	int row = zero/3;
	int col = zero%3;
	int neighborIndex,temp,x,y;
	vector<vector<int> > neighbors;
	for(pair<int,int> &mv : move) {
		x=row+mv.first;
		y=col+mv.second;
		if(x<0||x>=3||y<0||y>=3) {
			continue;
		}
		neighborIndex = x*3 + y;
		vector<int> neighbor;
		for(int i = 0; i < 9; i++) {
			neighbor.push_back(curr->board[i]);
		}
		neighbor[neighborIndex] = curr->board[zero];	
		neighbor[zero] = curr->board[neighborIndex];
		neighbors.push_back(neighbor);
	}
}