// Matriculation number: 40596285
// Author: Jack Millar
// Date of last modification: 16/04/2023
// Coursework 2

#pragma once
#include <string>
struct Node
{
    Node *left;
    Node *right;
    std::string name;
    std::string value;
};

class BST
{
public:
    BST();
    BST(BST const &other);
	//Node *copy_helper(const Node*); // Helper function for copy constructor
    ~BST();
    BST& operator=(const BST &rhs);
    void insert_constant(std::string name, std::string value);
    std::string to_string() const;
    std::string get_value(std::string name) const;
    int num_constants() const;

private:
    Node *root;
};

    

