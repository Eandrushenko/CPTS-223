#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "dsexceptions.h"
#include <iostream>    // For NULL
#include <queue>  // For level order printout
#include <vector>
#include <algorithm> // For max() function
using namespace std;

// AvlTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// int size( )            --> Quantity of elements in tree
// int height( )          --> Height of the tree (null == -1)
// void insert( x )       --> Insert x
// void insert( vector<T> ) --> Insert whole vector of values
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted (in) order
// void printPreOrder( )  --> Print tree in pre order
// void printPostOrder( ) --> Print tree in post order
// void printInOrder( )   --> Print tree in *in* order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class AvlTree
{
public:
	AvlTree() : root(NULL)
	{ }

	AvlTree(const AvlTree & rhs) : root(NULL)
	{
		*this = rhs;
	}

	~AvlTree()
	{
		cout << " [!] Destructor called." << endl;
	}

	/**
	 * Find the smallest item in the tree.
	 * Throw UnderflowException if empty.
	 */
	const Comparable & findMin() const
	{
		if (isEmpty())
			throw UnderflowException();
		return findMin(root)->element;
	}

	/**
	 * Find the largest item in the tree.
	 * Throw UnderflowException if empty.
	 */
	const Comparable & findMax() const
	{
		if (isEmpty())
			throw UnderflowException();
		return findMax(root)->element;
	}

	/**
	 * Returns true if x is found in the tree.
	 */
	bool contains(const Comparable & x) const
	{
		return contains(x, root);
	}

	/**
	 * Test if the tree is logically empty.
	 * Return true if empty, false otherwise.
	 *  TODO: Implement
	 */
	bool isEmpty() const
	{
		if (root == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * Return number of elements in tree.
	 */
	int size()
	{
		int count = 0;
		return size(root, count);
	}

	/**
	 * Return height of tree.
	 *  Null nodes are height -1
	 */
	int height()
	{
		return height(root);
	}

	/**
	 * Print the tree contents in sorted order.
	 */
	void printTree() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printInOrder(root);
	}

	/**
	 * Print the tree contents in sorted order.
	 */
	void printInOrder() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printInOrder(root);
	}

	/**
	 * Print the tree contents in pre order.
	 */
	void printPreOrder() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printPreOrder(root);
	}

	/**
	 * Print the tree contents in post order.
	 */
	void printPostOrder() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printPostOrder(root);
	}

	/**
	 * Make the tree logically empty.
	 */
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/**
	 * Insert x into the tree; duplicates are ignored.
	 */
	void insert(const Comparable & x)
	{
		insert(x, root);
	}

	/**
	 * Insert vector of x's into the tree; duplicates are ignored.
	 */
	void insert(vector<Comparable> vals)
	{
		for (auto x : vals) {
			insert(x, root);
		}
	}


	/**
	 * Remove x from the tree. Nothing is done if x is not found.
	 *  TODO: Implement
	 */
	void remove(const Comparable & x)
	{
		//cout << "[!] Sorry, remove unimplemented; " << x << " still present" << endl;
	}


	/**
	 * Deep copy. - or copy assignment operator
	 *  Will be in part II
	 */
	const AvlTree & operator=(const AvlTree & rhs)
	{
		cout << " [!] Copy *assignment* operator called." << endl;
		return *this;
	}


	/*****************************************************************************/
private:
	struct AvlNode
	{
		Comparable element;
		AvlNode   *left;
		AvlNode   *right;
		int       height;

		AvlNode(const Comparable & theElement, AvlNode *lt,
			AvlNode *rt, int h = 0)
			: element(theElement), left(lt), right(rt), height(h) { }
	};

	AvlNode *root;

	/**
	 * Internal method to count nodes in tree
	 *  TODO: Implement
	 */
	int size(AvlNode * & t, int & count)
	{
		count = 1;
		if (t == nullptr)
		{
			return 0;
		}
		else
		{
			count += size(t->left, count);
			count += size(t->right, count);
			return count;
		}
	}

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 *  TODO: Implement
	 */
	void insert(const Comparable & x, AvlNode * & t)
	{
		if (t == nullptr)
		{
			AvlNode *pMem = nullptr;
			pMem = new AvlNode(x, nullptr, nullptr, 0);
			t = pMem;
		}
		else if (x > t->element)
		{
			insert(x, t->right);
		}
		else if (x < t->element)
		{
			insert(x, t->left);
		}

		AvlNode *y = t->left;
		AvlNode *z = t->right;

		if (((height(y) - height(z)) > 1) && (x < t->left->element))
		{
			rotateWithLeftChild(t);
		}
		if (((height(y) - height(z)) < -1) && (x > t->left->element))
		{
			rotateWithRightChild(t);
		}
		if (((height(y) - height(z)) > 1) && (x > t->left->element))
		{
			doubleWithRightChild(t);
		}
		if (((height(y) - height(z)) < -1) && (x < t->left->element))
		{
			doubleWithLeftChild(t);
		}
		

		
	}

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     *  You'll need this for deletes
     *  TODO: Implement
     */
    AvlNode * findMin( AvlNode *t ) const
    {
		t = root;
		while (t != nullptr)
		{
			t = t->left;
		}
		return t;
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     *  TODO: Implement
     */
    AvlNode * findMax( AvlNode *t ) const
    {
		t = root;
		while (t != nullptr)
		{
			t = t->right;
		}
		return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     *  TODO: Implement
     */
    bool contains( const Comparable & x, AvlNode *t ) const
    {
		if (t != nullptr)
		{
			if (t->element == x)
			{
				return true;
			}
			else
			{
				return contains(x, t->left) || contains(x, t->right);
			}
		}
		return false;
    }

/******************************************************/

    /**
     * Internal method to make subtree empty.
     * 
     */
    void makeEmpty( AvlNode * & t )
    {
       // Will be in part II
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     *  TODO: Implement
     */
    void printInOrder( AvlNode *t ) const
    {
		if (t != nullptr)
		{
			printInOrder(t->left);
			cout << t->element << " ";
			printInOrder(t->right);
		}
    }

    /**
     * Internal method to print a subtree rooted at t in pre order.
     *  TODO: Implement
     */
    void printPreOrder( AvlNode *t ) const
    {
		if (t != nullptr)
		{
			cout << t->element << " ";
			printInOrder(t->left);
			printInOrder(t->right);
		}
    }

    /**
     * Internal method to print a subtree rooted at t in post order.
     *  TODO: Implement
     */
    void printPostOrder( AvlNode *t ) const
    {
		if (t != nullptr)
		{
			printInOrder(t->left);
			printInOrder(t->right);
			cout << t->element << " ";
		}
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode * clone( AvlNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new AvlNode( t->element, clone( t->left ), clone( t->right ), t->height );
    }


    // Avl manipulations
    /**
     * Return the height of node t or -1 if NULL.
     *  TODO: Implement
     */
    int height( AvlNode *t ) const
    {
		int left = 0, right = 0;
		if (t == nullptr)
		{
			return -1;
		}
		else
		{
			left = height(t->left);
			right = height(t->right);
		}
		if (left > right)
		{
			return (left + 1);
		}
		else
		{
			 return (right + 1);
		}
    }


    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }


    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     *  TODO: Implement
     */
    void rotateWithLeftChild( AvlNode * & k2 )
    {
		AvlNode *y = k2->left;

		k2->left = y->right;
		y->right = k2;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     *  TODO: Implement
     */
    void rotateWithRightChild( AvlNode * & k1 )
    {
		AvlNode *y = k1->right;

		k1->right = y->left;
		y->left = k1;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     *  TODO: Implement
     */
    void doubleWithLeftChild( AvlNode * & k3 )
    {
		AvlNode *y = k3->left;
		AvlNode *z = y->right;

		k3->left = z->right;
		y->right = z->left;

		z->right = k3;
		z->left = y;
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     *  TODO: Implement
     */
    void doubleWithRightChild( AvlNode * & k1 )
    {
		AvlNode *y = k1->right;
		AvlNode *z = y->left;

		k1->right = z->left;
		y->left = z->right;

		z->left = k1;
		z->right = y;
    }
};

#endif
