#include "Problem.h"

Problem::Problem(vector<int> startVector, int heurOption) {
	this->init = new Node(startVector,heurOption);
	this->heurOption=heurOption;
	vector<int> goalVector(9,0);
	for(int i = 0; i < 8; i++) goalVector[i]=i+1;
	this->goal = new Node(goalVector,heurOption);
	move.push_back({0,1});
	move.push_back({0,-1});
	move.push_back({1,0});
	move.push_back({-1,0});
	pq.clear();
}


bool Problem::findGoal() {
	pq.insert({0,this->goal});
	while(!pq.empty()) {
		auto front = pq.begin();
		this->curr=front->second;
		int cost = front->first;
		pq.erase(front);
		if(curr->board==goal->board) { //in goal state
			return true;
		}
		visited.insert(curr->board);
		expand(cost);
	}
	return false;
}


void Problem::expand(int cost) {
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
		if(visited.count(neighbor)) continue;
		else {
			Node* neigh = new Node(neighbor,heurOption);
			pq.insert({cost+neigh->h, neigh});
		}

	}
}

bool isEqual(const vector<int>& a, const vector<int>& b) {
	if(a.size()!=b.size()) return false;
	for(int i = 0; i < a.size(); i++) {
		if(a[i]!=b[i]) return false;
	}
	return true;
}
