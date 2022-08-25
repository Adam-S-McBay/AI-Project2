#ifndef NODE_H
#define NODE_H
//note : need to change Node class to Node class
class Node
{
	public:
		//int state = 1;
		int square[9] = {1,2,3, 8,0,4, 7,6,5};
		int depth = 0;  //depth of node or g value, increment with setDepth when creating a new puzzle node
		int hValue = 0; // heuristic value, set during function call 
		int fValue = 0; // g + h , sort open based on this
		Node();
		Node(int a, int b, int c, int d, int e, int f, int g, int h, int i);
		Node(const Node &p);
		//possible moves initialized to -1 to signify no possible moves
		//if possible moves found by member function, set these to indexes
		//that can swap with empty square
		int possibleMoves [4] = {-1,-1,-1,-1};
		
		
		void setDepth(int d);
		int getDepth();
		void setHValue(int h);
		//int getHValue();
		void setFValue(int f);
		//int getFValue();
		
		int getNodeState(int x);
		void setNodeState(int x, int n);
		void swapPositions(int swapped);
		int calcAdjacent(int square1, int square2);
		int findEmpty();
		void printNode();
		int findPossibleMoves();
	//protected:
};

#endif