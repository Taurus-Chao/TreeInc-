## The implementation of Binary Search Tree(BST) in C++ on platform VS2013. 

The project consists of:
1. *Mytree.h* and *Mytree.cpp*
The definition and the implementation of BST including data members and the permitted operations on the data structure. The operations contain:
* isempty: descide the tree is empty or not.
* makeEmpty: make the tree empty.
* size: return the size of the tree.
* maxdepth: return the maxmum depth of the tree.
* print_preorder: print the tree in preorder.
* find: find the element in the tree.
* findMin: find the minmus element in the tree.
* findMax: find the maximum element in the tree.
* insert: insert the element in the tree.
* mydelete: delete the element in the tree.

2. *MytreeFun.h* and *MytreeFun.cpp*
Some functions based on BST, including:
* floor: Look for the first node in the tree whose element value is not greater than k.
* ceiling:Look for the first node in the tree whose element value is not less than k.
* isBST:deside the tree is BST or not.
* mirror: mirror the tree.
* isSameTree: judge the given trees is equal or not.
* bool isfoldable:judge the BST is foldable or not.
*	getIterative: get the node with the specified element value k in a circular method.
*	insertIterative: insert the node with value k in in a circular method.
*	 printInorderIterative: print the tree in order with circular method.
*	 printPreorderIterative: print the tree in preorder with circular method.
*	 printPostorderIterative:print the tree in postorder with circular method.
* printLevelOrder :print the tree in order of layers.
* printLevelOrderReverse: print the tree in the reverse order of layers.
* printLevelOrderZigzag: print the tree in zigzag order of layers.
* buildTreeBy_PreIn: the results of first order traversal and middle order traversal are used to restore the binary tree
* sortedArray2BST: construct a BST with as little depth as possible from a given sorted array.
* sortedList2BST: construct BST with as little depth as possible from a given sorted list.

* hasPathSum: determine if there is a path from the root node to the leaf so that the elements on the path sum to k.
* printPathSum: print the path from the root node to the leaf so that the elements on the path and the path is k.
* findPaths: determine if there is a path from any node to any path so that the sum of the elements on the path is k (depth-first search).
* lowestCommonAncestor: find the closest common ancestor of two nodes in the BST tree.
