// Matriculation number: 40596285
// Author: Jack Millar
// Date of last modification: 16/04/2023
// Coursework 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "BST.h"

using namespace std;

void inputTree(string input, BST &tree)
{
	
	//Init variables
	string line;	
	string token;
	string temp;
	int count = 0;
	
	//	Read file
	ifstream inFile(input);
	
	//	plit file into each lines
	while (getline(inFile ,line))
	{
		// Search for lines with "define" in it
		if (line.find("#define") == 0)
		{	
			// Start tokenising
			stringstream stream (line);
			while ( stream >> token ){
				// Get second element and store it to temporary variable
				if (count == 1)
				{
					temp = token;
				}
				// Get third element and insert temporary + element into tree
				if (count == 2)
				{
					tree.insert_constant(temp, token);
				}
				// Continue counter
				count++;
			}
			// Reset counter to 0
			count = 0;
		}
	}
	
	// Close file
	inFile.close();
}

void outputFile(string input, BST &tree)
{
	
	// Init variables
	string line;	
	string token;
	string temp;
	string connectLine;
	
	// Open file for reading
	ifstream inFile(input);
	
	// Create the name for the output file
	string output = input.substr(0, input.length() - 2);
	output += ".o";

	// Open file for outputting
	ofstream outFile(output);
	
	// Print file to command
	while (getline(inFile, line))
	{
		// Only get lines that done include "#define"
		if (line.find("#define") != 0)
		{	
			// Reset connectLine
			connectLine = "";
			// Start tokenising
			stringstream stream (line);
			while ( stream >> token )
			{
				// Run token through binary tree and store the result in a temporary variable
				temp = tree.get_value(token);
				if (temp == "")
					temp = token;
				// Reconstruct the line
				connectLine += temp + " ";
			}
		// Output line to file
		outFile << connectLine << endl;			
		}
	}
	
	// Close both files
	inFile.close();
	outFile.close();
}


int main(int argc, char**argv)
{
	// Get console input and assign variable to iter_swap
	string input = argv[1];
	
	// Initialise Binary tree
	BST tree;
	
	/* Function tasks:
	1. Reads file
	2. Finds constant_name and value
	3. Insert into binary tree
	*/
	inputTree(input, tree);
	
	
	/* Function tasks:
	1. Read file
	2. Create new output file
	3. Replace data names with data values
	4. Print to output file 
	*/
	outputFile(input, tree);
}