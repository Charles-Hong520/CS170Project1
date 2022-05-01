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
		vector<int> inputPuzzle(9); for(int &e:inputPuzzle) cin>>e;
		cout<<"Enter your choice of algorithm\n";
		cout<<"1. Uniform Cost Search\n";
		cout<<"2. A* with the Misplaced Tile heuristic\n";
		cout<<"3. A* with the Euclidean distance heuristic\n";
		int heuristicChoice; cin>>heuristicChoice;

		//print algorithm outputs here.
	} else {

	}

	return 0;
}