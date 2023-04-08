/*
 * Octavio Cruz
 * Gia Trinh
 *
 *  CIS 22C
 *  Assignment 6
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include <iomanip>

using namespace std;

template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* left;
        Node* right;

        Node(bstdata newdata){
            data = newdata;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    void insertNode(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrint(ostream& out, Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrint(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrint(ostream& out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyNode(Node* copy);
    //recursive helper function to the copy constructor

    void freeNode(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchNode(Node* root, bstdata data) const;
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimum(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximum(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* removeNode(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSize(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeight(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:

    /**constructors and destructor*/

    BST();
    //Instantiates a new BST

    BST(const BST &bst);
    //copy constructor

    ~BST();
    //deallocates the tree memory

    /**access functions*/

    bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const;
    //determines whether the BST is empty

    int getSize() const;
    //returns the size of the tree

    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bool search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};
#endif /* BST_H_ */

template <class bstdata>
BST<bstdata>::BST()
{
	root = NULL;
	//cout << "Constructor was called." << endl;
}

template <class bstdata>
BST<bstdata>::BST(const BST &bst)
{
		copyNode(bst.root);
}

template<class bstdata>
void BST<bstdata>::copyNode(Node* copy)
{
	if(copy == NULL)
	{
	    return;
	}
	else
	{
		insert(copy->data);
		copyNode(copy->left);
		copyNode(copy->right);
	}
}

template <class bstdata>
BST<bstdata>::~BST()
{
	//cout << "\nDestructor was called." << endl;
	freeNode(root);
}

template<class bstdata>
void BST<bstdata>::freeNode(Node* root)
{
    if(root == NULL)
    {
    		return;
    }
    else
    {
    	freeNode(root->left);
    	freeNode(root->right);
    	delete root;
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out, Node* root) const //Ok
{
	if(root == NULL)
		return;
	else
	{
		inOrderPrint(out, root->left);
		out << root->data << " ";
		inOrderPrint(out, root->right);
		cout << endl;
	}
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const
{
	inOrderPrint(out, root);
	//cout << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out, Node* root) const //OK
{
	if(root == NULL)
		return;
	else
	{
		out << root->data << " ";
		preOrderPrint(out, root->left);
		preOrderPrint(out, root->right);
	}
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const
{
	preOrderPrint(out, root);
	cout << endl;
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out, Node* root) const //OK
{
	if(root == NULL)
		return;
	else
	{
		postOrderPrint(out, root->left);
		postOrderPrint(out, root->right);
		out << root->data << " ";
	}
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const
{
	postOrderPrint(out, root);
	cout << endl;
}

template <class bstdata>
void BST<bstdata>::insertNode(Node* root, bstdata data) //OK
{
	if( data == root->data)
	{
		return;
	}
	else
	{
		if (data < root->data)
		{
			if(root->left == NULL)
			{
				root->left = new Node(data);
			}
			else
			{
				insertNode(root->left,data);
			}
		}
		else
		{
			if(root->right == NULL)
			{
				root->right = new Node(data);
			}
			else
			{
				insertNode(root->right,data);
			}
		}
	}
}

template <class bstdata>
void BST<bstdata>::insert(bstdata data) //OK
{
    if (root == NULL)
    {
        root = new Node(data); //if the tree is empty insert the value at the root
    }
    else
    {
        insertNode(root, data); //otherwise call the helper function, passing it the root
    }
}

template <class bstdata>
bool BST<bstdata>::searchNode(Node* root, bstdata data) const //OK
{
	if(data == root->data)
		return true;
	else if(data < root->data)
		if(root->left == NULL)
			return false;
		else
			 searchNode(root->left, data);
	else
	{
		if(root->right == NULL)
			return false;
		else
			 searchNode(root->right, data);
	}
}

template <class bstdata>
bool BST<bstdata>::search(bstdata data) const //OK
{
//Add code to check for the precondition here
	assert(!isEmpty());
	if (data == root->data)
        return true;
	else
		return searchNode(root, data);
}

template <class bstdata>
bstdata BST<bstdata>::minimum(Node* root) const //OK
{
	if(root->left != NULL)
		return minimum(root->left);
	else
		return root->data;
}

template <class bstdata>
bstdata BST<bstdata>::minimum() const
{
	assert(!isEmpty());
	return minimum(root);
}

template <class bstdata>
bstdata BST<bstdata>::maximum(Node* root) const
{
	if (root->right != NULL)
	{
		return maximum(root->right);
	}
	else
	{
		return root->data;
	}
}

template <class bstdata>
bstdata BST<bstdata>::maximum() const
{
	if (!isEmpty())
	{
		return maximum(root);
	}
	else
	{
		return 0;
	}
}

template <class bstdata>
typename BST<bstdata>::Node* BST<bstdata>::removeNode(Node* root, bstdata data) //OK
{
	if(root == NULL)
		return root;
	else if(data < root->data)
	{
		root->left = removeNode(root->left,data);
	}
	else if(data> root->data)
	{
		root->right = removeNode(root->right,data);
	}
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else if(root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else
		{
			root->data = minimum(root->right);
			root->right = removeNode(root->right,minimum(root->right));
		}
	}
	return root;
}

template <class bstdata>
void BST<bstdata>::remove(bstdata data)
{
	assert(!isEmpty());
	root = removeNode(root, data);	//add code to handle the preconditions

}

template <class bstdata>
bstdata BST<bstdata>::getRoot() const
{
	assert(!isEmpty());
	return root->data; //returns the data contained at the root node
}

template <class bstdata>
bool BST<bstdata>::isEmpty() const
{
	if(root == NULL)
		return true;
	else
		return false;
}

template <class bstdata>
void BST<bstdata>::getSize(Node* root, int& size) const
{
	if ( root != NULL)
	{
		if (root->left)
		{
			getSize(root->left, ++size);
		}
		if (root->right)
		{
			getSize(root->right, ++size);
		}
	}
}

template <class bstdata>
int BST<bstdata>::getSize() const
{
	int size = 0;
	if (!isEmpty())
	{
		getSize (root, ++size);
	}
	return size;
}

template <class bstdata>
int BST<bstdata>::getHeight(Node* root) const
{
	if (root == 0)
	{
		return 0;
	}
	else if (getHeight(root->right) > getHeight(root->left))
	{
		return 1 + getHeight(root->right);
	}
	else
	{
		return 1 + getHeight(root->left);
	}
}

template <class bstdata>
int BST<bstdata>::getHeight() const
{
	int h = getHeight(root);
	return h;

}
