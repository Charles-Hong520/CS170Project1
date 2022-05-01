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
	set<pair<int,pair<int,Node*>>> pq; //min pq;
	Node* init;
	Node* goal;
	Node* curr;
	vector<pair<int,int>>  move;
	int heurOption;
public:
	Problem(vector<int> v, int heurOption);
	bool findGoal();
	int maxPQSize;
	set<vector<int>> visited;
	void printState(int cost);
	Node* getCurr() {return curr;}
private:
	void expand(int cost);
};
#endif