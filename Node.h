#ifndef __NODE__
#define __NODE__
#include <cmath>
#include <vector>
using std::vector;
using std::sqrt;
using std::pow;
struct Node {
	vector<int> board;//game board
	vector<Node*> neighbors;//need to impl traceback
	double h; //heuristic value

	//constructor for Node Objects
	Node(vector<int>& v,int heurOption) {
		for(int num : v) {
			board.push_back(num);
		}
		h = calcHeur(heurOption);
	}
	
	//calculate heuristic based on choice
	double calcHeur(int option) {
		//0 is uniform
		//1 is misplaced tiles
		//2 is manhattan/euclidean dist
		option--;
		double h = 0;
		if(option==0) return 0;
		else if(option==1) {
			for(int i = 0; i < 8; i++) {
				if(board[i]!=i+1) h++;
			}
			return h;
		} else if(option==2) {
			int currRow,currCol; //traversing index i
			int goalRow,goalCol; //our board vector's val
			for(int i = 0; i < 9; i++) {
				if(board[i]==0) continue;
				currRow	= i/3;
				currCol = i%3;
				goalRow	= (board[i]-1)/3;
				goalCol = (board[i]-1)%3;
				h+=sqrt(pow(currRow-goalRow,2)+pow(currCol-goalCol,2));
			}
			return h;
		} else if(option==3) {
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
			return h;
		}
		return -1; //wrong options
	}
};
#endif