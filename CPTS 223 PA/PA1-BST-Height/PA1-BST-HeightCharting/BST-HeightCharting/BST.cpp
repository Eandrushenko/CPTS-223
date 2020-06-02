#include "BST.h"

BST::BST()
{
	mpRoot = NULL;
}

BST::~BST()
{

}

Node * BST::getRoot()
{
	return mpRoot;
}

void BST::setRoot(Node * const newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(Node *& pTree, const int &newNumber)
{
	if (pTree == NULL)
	{
		Node *pMem = NULL;
		pMem = new Node(newNumber);
		pTree = pMem;
	}
	else if (newNumber > pTree->getNumber())
	{
		insert(pTree->getRight(), newNumber);
	}
	else if (newNumber < pTree->getNumber())
	{
		insert(pTree->getLeft(), newNumber);
	}
	else
	{
		insert(pTree, rand() % 1000000);
		//cout << "Duplication" << endl;
	}
}

void BST::insert(const int &newNumber)
{
	insert(this->mpRoot, newNumber);
}

void BST::preorderTraversal(Node *& pTree)
{
	if(pTree != NULL)
	{
		cout << pTree->getNumber() << endl;
		preorderTraversal(pTree->getLeft());
		preorderTraversal(pTree->getRight());
	}
}

void BST::preorderTraversal()
{
	preorderTraversal(this->mpRoot);
}

int BST::maxHeight(Node *& pTree)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (pTree == NULL)
	{
		return -1;
	}
	else
	{
		 leftHeight = maxHeight(pTree->getLeft());
		 rightHeight = maxHeight(pTree->getRight());
	}
	if (leftHeight > rightHeight)
	{
		return (leftHeight + 1);
	}
	else if (leftHeight <= rightHeight)
	{
		return (rightHeight + 1);
	}
	else
	{
		cout << "Error in the maxHeight Function" << endl;
	}
}

int BST::maxHeight()
{
	int height = 0;
	
	height = maxHeight(this->mpRoot);
	
	return height;
}





