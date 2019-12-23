#include"MytreeFun.h"
#include<iostream>
#include<list>
using namespace std;

int main()
{
	MytreeFun t1;

	t1.insertIterative(6);
	t1.insertIterative(4);
	t1.insertIterative(8);
	t1.insertIterative(3);
	t1.insertIterative(5);
	t1.insertIterative(7);
	t1.insert(9);
	//t1.insert(11);
	//cout << endl;
	//t1.printLevelOrderZigzag();

	/*int pre[] = { 4,1,3,5,2,8,6,7,9 };
	int in[] = {4,3,2,5,8,1,7,9,6 };
	t1.buildTreeBy_PreIn(pre, in,9);
	t1.printPostorderIterative();*/

	/*int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	t1.sortedArray2BST(array, 8);
	t1.printLevelOrder();*/

	//list<int> l;
	//l.push_back(1);
	//l.push_back(2);
	//l.push_back(3);
	//l.push_back(4);
	//t1.sortedList2BST(l);
	//t1.printLevelOrder();

	//cout<<t1.findPaths(16);

	Node* n1 = t1.find(3);
	Node* n2 = t1.find(8);
	Node *res = t1.lowestCommonAncestor(n1, n2);
	cout << res->element;

	system("pause");
}