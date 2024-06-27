Toolchain:
Visual Studio 2022 Developer Command Prompt v17.4.4

Makefile targets
nmake libary - Creates a .lib file from BST.cpp 
nmake compReplace - compiles the replace.cpp file and links to BST libary
nmake compTest - compiles the BSTtest.cpp file and links to BST libary
nmake clean - deletes all .obj, .exe, and .lib files in the folder

How to run:
start by creating the libary using nmake libary
1. run test application,
	use nmake compTest to compile the test application then input "BSTtest.exe" to execute it
2. run replace application
	use nmake compReplace to compile the replace application then input "replace.exe " + [file_name] to execute it
	

