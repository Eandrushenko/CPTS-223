#include "BSTNode.h"

Node::Node(int newNumber)
{
	mNumber = newNumber;
	mpRight = NULL;
	mpLeft = NULL;
}

Node::~Node()
{

}

int Node::getNumber() const
{
	return mNumber;
}

Node *& Node::getRight()
{
	return mpRight;
}

Node *& Node::getLeft()
{
	return mpLeft;
}

void Node::setNumber(const int newNumber)
{
	mNumber = newNumber;
}

void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}


