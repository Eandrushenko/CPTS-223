#pragma once

#include "BSTNode.h"

class BST
{
public:
	//Constructor
	BST();

	//Destructor
	~BST();

	//Getters
	Node *getRoot();

	//Setters
	void setRoot(Node * const newRoot);

	//Insert
	void insert(const int &newNumber);

	//Traversal Functions
	void preorderTraversal();
	int maxHeight();
	
private:
	Node *mpRoot;

	void insert(Node *& pTree, const int &newNumber);
	void preorderTraversal(Node *& pTree);
	int maxHeight(Node *& pTree);

};
