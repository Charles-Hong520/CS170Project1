#ifndef __PROBLEM__
#define __PROBLEM__
#include "Node.h"
#include <set>
#include <utility>
using std::set;
using std::pair;
using std::vector;
class Problem {
private:
	set<pair<int,Node*> > pq; //min pq;
	set<vector<int>> visited;
	Node* init;
	Node* goal;
	Node* curr;
	vector<pair<int,int> > move;
	int heurOption;
public:
	Problem(vector<int> v, int heurOption);
	bool findGoal();
private:
	void expand(int cost);
	bool isEqual(const vector<int>& a, const vector<int>& b);

};
#endif