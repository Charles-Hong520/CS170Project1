#ifndef __NODE__
#define __NODE__
#include <cmath>
#include <vector>
using std::vector;
struct Node {
	vector<int> board;
	vector<Node*> neighbors;
	int h;

	Node(vector<int>& v,int heurOption) {
		for(int num : v) {
			board.push_back(num);
		}
		h = calcHeur(heurOption);
	}
	
	int calcHeur(int option) {
		//0 is uniform
		//1 is misplaced tiles
		//2 is manhattan/euclidean dist

		int h = 0;
		if(option==0) return 0;
		else if(option==1) {
			for(int i = 0; i < 9; i++) {
				if(board[i]!=i+1) h++;
			}
		} else if(option==2) {
			int currRow,currCol; //traversing index i
			int goalRow,goalCol; //our board vector's val
			for(int i = 0; i < 9; i++) {
				if(board[i]==0) continue;
				currRow	= i/3;
				currCol = i%3;
				goalRow	= (board[i]-1)/3;
				goalCol = (board[i]-1)%3;
				h+=abs(currRow-goalRow)+abs(currCol-goalCol);
			}
		}
		return -1; //wrong options
	}
};
#endif