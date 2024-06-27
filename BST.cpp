// Matriculation number: 40596285
// Author: Jack Millar
// Date of last modification: 16/04/2023
// Coursework 2


#include "BST.h"
#include <iostream>
using namespace std;

Node* copy_helper(const Node *orig);

string to_string_helper(Node *root); //Prototype of a helper function,
									 //You can add additional helper functions
									//to this code file

BST::BST()
{
    this->root = nullptr;
}


BST::BST(const BST &other)
{	
   root = copy_helper(other.root);
}

// Create a copy of a binary search tree
// Parameters: orig, the original tree
// Returns: A copy of the tree
Node* copy_helper(const Node *orig)
{
	// Check if current node has anything in it/act as a cut off point for the recursion
	if (orig == nullptr)
	{
		return nullptr;
	}
	else
	{
		// Create new node
		Node *copyNode = new Node;
		// Copy values to new node
		copyNode->name = orig->name;
		copyNode->value = orig->value;
		// Recurse through the tree
		copyNode->left = copy_helper(orig->left);
		copyNode->right = copy_helper(orig->right);
		// return the node
		return copyNode;
	}
}

void destroy_helper(Node *tree)
{
	if (tree != nullptr)
	{
		destroy_helper(tree->left);
		destroy_helper(tree->right);
		delete tree;
	}
}

BST::~BST()
{
	// Call function helper to destroy tree
	destroy_helper(this->root);
}

// A helper function to allow recursive calls
// You can add helper functions like this for the other methods,
// to recursively move through the tree
string to_string_helper(Node *root) 
{
    if(root == nullptr)
    {
        return "";
    }
    else
    {
        return to_string_helper(root->left) + 
            root->name + "=" + root->value + " " +
            to_string_helper(root->right);
    }
}

string BST::to_string() const
{
    string ret = to_string_helper(this->root);
    if(ret.length() > 1)
    {
         ret.pop_back(); //remove final space
    }
    //cout << ret << endl;
    return ret;
}

// A helper function to insert data into a tree
// Parameters: tree, the binary tree to insert into, names/values, the data to insert into the tree
void insert_helper(Node **tree, string names, string values)
{
	// Check if the recursive function has reached the bottom of the tree
	if (*tree == nullptr)
	{
		// Create new node
		*tree = new Node;
		// Set new value
		(*tree)->name = names;
		(*tree)->value = values;
		
		// Set branches to nullptr
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
	} else
		{
			// Let the tree be sorted in alphabetical order for names
			if (names < (*tree)->name)
			{
				 insert_helper(&((*tree)->left), names, values);			 
			}
			else if (names > (*tree)->name)
			{
				insert_helper(&((*tree)->right), names, values);
			}
		}

}

void BST::insert_constant(string name, string value)
{
   insert_helper(&(this->root), name, value);
}

// Searches through the tree to find a certain value
// Parameters: tree, the tree being searched. key, the name being used to search for
// Returns: the value that is in the same node as the searched key
string search(Node *tree, string key)
{

	Node *temp = new Node;
	// Set a temporary tree to search through
	temp = tree;
	// Run the loop until temp points to a NULL pointer.
	while(temp != NULL)
	{
		// Check if name == key
		if(temp->name == key)
		{
			return temp->value;
		}
		// Shift pointer to left child.
		else if(temp->name > key)
			temp = temp->left;
		// Shift pointer to right child.
		else
			temp = temp->right;
	}
	// if nothing is found then return ""
	return "";
}
 
string BST::get_value(string name) const
 {
	string value = search(this->root, name);
	return value;
 }
 
 // Counts the number of nodes in a tree
 // Parameters: tree, the binary search tree being counted
 // Returns: the number of nodes
 int count_helper(Node *tree)
{
	// If tree is nullptr then we have reached the bottom of a branch
    if (tree == nullptr) {
        return 0;
    }
	// Count down the left hand side of the tree then the right hand side
    int leftCount = count_helper(tree->left);
    int rightCount = count_helper(tree->right);
	// Add all the values together
    return leftCount + rightCount + 1;
}

int BST::num_constants() const
{
    int count = count_helper(this->root);
	return count; 
}

BST& BST::operator=(const BST &rhs)
{
	// Use the copy_helper function to copy the tree
	Node *new_tree = copy_helper(rhs.root);
	root = new_tree;
	return *this; 
}