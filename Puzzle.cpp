#include "Puzzle.h"
#include <iostream>
#include <cmath>
//switched to Node class, not in use
Puzzle::Puzzle() {
}
//default constructor
int Puzzle::getPuzzleState(int x) {
	//std::cout << "State at " << x << " = " << this->square[x];
	return square[x];
}
//custom configuration constructor
Puzzle::Puzzle(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	square[0] = a;
	square[1] = b;
	square[2] = c;
	square[3] = d;
	square[4] = e;
	square[5] = f;
	square[6] = g;
	square[7] = h;
	square[8] = i;
}

//copy constructor
Puzzle::Puzzle(const Puzzle &p) {
	
	std::cout << "Constructor for loop:";
	for (int i=0; i<9; i++) {
		std::cout << "square[i]: " << square[i] <<"p.square[i]" << p.square[i] <<std::endl;
		this->square[i] = p.square[i];
	}
	this->depth = p.depth;
}
//set a square[x] in puzzle obj to value n
void Puzzle::setPuzzleState(int x, int n) {
	square[x] = n;
}

void Puzzle::setDepth(int d) {
	depth = d;
}
int Puzzle::getDepth() {
	return depth;
}
void Puzzle::setHValue(int h) {
	hValue = h;
}

void Puzzle::setFValue(int f) {
	fValue = f;
}

//assuming we only swap with the empty (0) position, then whatever square is adjacent to
//it will return either 1 for horizontally adjacent, 3 for vertically adjacent or 0 for
//not adjacent
int Puzzle::calcAdjacent(int square1, int square2) {
	int adj = 0;
	//Squares are adjacent in the horizontal plane
	if (abs(square1 - square2) == 1 && square1 + square2 != 5 && square1 + square2 != 11){
		adj = 1;
	}
	//Squares are adjacent in the vertical plane
	else if (abs(square1 - square2) == 3) {
		adj = 3;
	}
	
	return adj;
}
//return the empty square's index
int Puzzle::findEmpty() {
	int index = 0;
	for (int i=0; i<9; i++) {
		if (square[i] == 0)
			index = i;
	}
	return index;
}

//swap a square at square[x] with the empty square at square[findEmpty()]
//and set the swapped square[x] to empty [0]
void Puzzle::swapPositions(int x) {
	// if empty square is adjacent to attempted swap, swap them
	std::cout<< "square[findEmpty()] : " << square[this->findEmpty()]<< std::endl;
	std::cout<< "findEmpty(): " << findEmpty() << std::endl;
	std::cout<< "square[x] : " << square[x]<< std::endl;
	if (calcAdjacent(x, findEmpty())) {
		std::cout<< "calcAdjacent true!" << std::endl;
		std::cout<< "square[findEmpty()] : " << square[findEmpty()]<< std::endl;
		std::cout<< "square[x] : " << square[x]<< std::endl;
		square[findEmpty()] = square[x];
		square[x] = 0;
		
	}
} 
void Puzzle::printPuzzle() {
	for (int i = 0; i<9; i++) {
		if (i == 3 || i == 6) 
			std::cout << std::endl; 
		std::cout << square[i] << " ";
	}
	std::cout << std::endl;
}

void Puzzle::findPossibleMoves() {
	switch (this->findEmpty()) {
		case 0 :
			possibleMoves[0] = 1;
			possibleMoves[1] = 3;
			break;
		case 1 :
			possibleMoves[0] = 0;
			possibleMoves[1] = 2;
			possibleMoves[2] = 4;
			break;
		case 2 :
			possibleMoves[0] = 1;
			possibleMoves[1] = 5;
			break;
		case 3 :
			possibleMoves[0] = 0;
			possibleMoves[1] = 4;
			possibleMoves[2] = 6;
			break;
		case 4 :
			possibleMoves[0] = 1;
			possibleMoves[1] = 3;
			possibleMoves[2] = 5;
			possibleMoves[3] = 7;
			break;
		case 5 :
			std::cout<<"case 5" << std::endl;
			possibleMoves[0] = 2;
			possibleMoves[1] = 4;
			possibleMoves[2] = 8;
			break;
		case 6 :
			std::cout<<"case 6" << std::endl;
			possibleMoves[0] = 3;
			possibleMoves[1] = 7;
			break;
		case 7 :
			std::cout<<"case 7" << std::endl;
			possibleMoves[0] = 6;
			possibleMoves[1] = 4;
			possibleMoves[2] = 8;
			break;
		case 8 :
			std::cout<<"case 8" << std::endl;
			possibleMoves[0] = 7;
			possibleMoves[1] = 5;
			break;
		}
		//for loop to test possibleMoves(), remove later
		//for (int i = 0; i<4; i++) {
		//	if (possibleMoves[i] != -1)
		//		std::cout << possibleMoves[i] << " ";
		//}
		std::cout << std::endl;
}