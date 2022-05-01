#ifndef __PROBLEM__
#define __PROBLEM__
#include "Node.h"
#include <set>
#include <utility>
using std::set;
using std::pair;
class Problem {
private:
	set<vector<int>> visited;
	Node* init;
	Node* goal;
	vector<pair<int,int> > move;
public:
	Problem(vector<int> v, int heurOption);
	bool findGoal();
private:
	void findNeighbors(Node* curr);
	vector<vector<int>> calcNext(Node* curr);
};
#endif