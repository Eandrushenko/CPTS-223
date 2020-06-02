#include "TestData.h"

void minitest()
{
	BST tree;
	
	tree.insert(10);
	tree.insert(5);
	tree.insert(1);
	tree.insert(7);
	tree.insert(14);
	tree.insert(17);
	tree.insert(19);
	tree.insert(18);

	tree.preorderTraversal();

	cout << "The height of the minitest tree is " << tree.maxHeight() << endl;
	cout << endl;

}


int randomNumber()
{
	int number = 0;
	number = rand() % 350000;
	return number;
}
