libary:
	cl /EHsc /c BST.cpp
	lib BST.obj

compReplace:
	cl /EHsc /c replace.cpp
	link replace.obj BST.lib

compTest:
	cl /EHsc /c BSTtest.cpp
	link BSTtest.obj BST.lib 
	
clean:
	del *.obj
	del *.exe
	del *.lib