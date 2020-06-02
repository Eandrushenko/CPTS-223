#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

class Node
{
public:
	//Constructor
	Node(int newNumber);

	//Destructor
	~Node();

	//Getters
	int getNumber() const;
	Node *& getRight();
	Node *& getLeft();

	//Setters
	void setNumber(const int newNumber);
	void setRight(Node * const newRight);
	void setLeft(Node * const newLeft);

private:
	int mNumber;
	Node* mpRight;
	Node* mpLeft;
};

