#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Problem.h"

int main() {
	int puzzleType;
	cout<<"Welcome to 862141833 chong039 8 puzzle solver.\n";
	cout<<"Type\"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
	cin>>puzzleType;
	if(puzzleType==2) {
		cout<<"Enter your own puzzle, use a zero to represent the blank\n";
		cout<<"Enter the first row, use space or tabs between numbers\n";
		cout<<"Enter the second row, use space or tabs between numbers\n";
		cout<<"Enter the third row, use space or tabs between numbers\n";
		vector<int> v(9); for(int &e:v) cin>>e;
		cout<<"Enter your choice of algorithm\n";
		cout<<"1. Uniform Cost Search\n";
		cout<<"2. A* with the Misplaced Tile heuristic\n";
		cout<<"3. A* with the Euclidean distance heuristic\n";
		int heuristicChoice; cin>>heuristicChoice;
		Problem p(v,heuristicChoice);
		bool found = p.findGoal();
		if(found) {
			cout<<"Goal!!!"<<endl;
			Node* curr = p.getCurr();
			for(int i = 0; i < 9; i++) {
				cout<<curr->board[i]<<' ';
				if(i%3==2) cout<<endl;
			}
		} else {
			cout<<"Search failed :("<<endl;
		}
		cout<<"Expanded Count: "<<p.getExpandCount();
		//print algorithm outputs here.
	} else {
		cout<<"testing default puzzle"<<endl;
		cout<<"1 2 3\n4 0 5 \n7 8 6"<<endl;
		cout<<"Enter your choice of algorithm\n";
		cout<<"1. Uniform Cost Search\n";
		cout<<"2. A* with the Misplaced Tile heuristic\n";
		cout<<"3. A* with the Euclidean distance heuristic\n";
		int heuristicChoice; cin>>heuristicChoice;
		// int a[9] = {1,2,3,4,0,5,7,8,6};
		int a[9] = {1,2,3,4,8,0,7,6,5};
		vector<int> v(9); 
		for(int i = 0; i < 9; i++) v[i]=a[i];
		Problem p(v,heuristicChoice);
		bool found = p.findGoal();
		if(found) {
			cout<<"Goal!!!"<<endl;
			Node* curr = p.getCurr();
			for(int i = 0; i < 9; i++) {
				cout<<curr->board[i]<<' ';
				if(i%3==2) cout<<endl;
			}
		} else {
			cout<<"Search failed :("<<endl;
		}
		cout<<"Expanded Count: "<<p.getExpandCount();

	}

	return 0;
}