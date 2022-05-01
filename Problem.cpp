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
	//expand function
	vector<vector<int>> neighbors = calcNext(curr);

}

vector<vector<int>> Problem::calcNext(Node* curr) {
	int zero = -1;
	for(int i = 0; i < 9; i++) {
		if(curr->board[i]==0) {
			zero=i;
			break;
		}
	}
	int row = zero/3;
	int col = zero%3;
	int neighborIndex,x,y;
	vector<vector<int> > next;
	for(pair<int,int> &mv : move) {
		x=row+mv.first;
		y=col+mv.second;
		if(x<0||x>=3||y<0||y>=3) {
			continue;
		}
		neighborIndex = x*3 + y;
		vector<int> neighbor;

		//deep copy of vector
		for(int i = 0; i < 9; i++) {
			neighbor.push_back(curr->board[i]);
		}

		//operation of swapping blank with number
		neighbor[neighborIndex] = curr->board[zero];	
		neighbor[zero] = curr->board[neighborIndex];
		next.push_back(neighbor);
	}
	return next;
}