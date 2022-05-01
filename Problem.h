#ifndef __PROBLEM__
#define __PROBLEM__
#include "Node.h"
#include <set>
#include <iostream>
#include <utility>
#include <algorithm>
using std::set;
using std::pair;
using std::vector;
using std::cout;
using std::endl;
class Problem {
private:
	set<pair<double,pair<int,Node*>>> pq; //min pq;
	Node* init; //init state
	Node* goal; //goal state
	Node* curr; //traversing state
	vector<pair<int,int>>  move; //4 directions
	int heurOption; //heuristic choice
public:
	/*
	constructs the problem with a start and goal
	node, and the heuristic type.
	and initializes all the other variables.
	*/ 
	Problem(vector<int> v, int heurOption);

	/*
	A* algorithm
	*/
	bool findGoal();

	//max size of the frontier
	int maxPQSize;
	
	//nodes that are expanded
	set<vector<int>> visited;

	//print the g and h vals, and the board
	void printState(double cost);

	//gets current state in the expansion
	Node* getCurr() {return curr;}
private:
	//inserts neighboring nodes into pq and expands
	void expand(double cost);
};
#endif