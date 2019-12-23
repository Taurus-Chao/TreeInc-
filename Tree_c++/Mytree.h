#ifndef MYTREE_H
#define MYTREE_H
//¶þ²æ²éÕÒÊ÷

class Node
{
public:
	int element;
	Node *right;
	Node *left;
	Node()
	{
		element = 0;
		left = nullptr;
		right = nullptr;
	}
};

class Mytree
{
public:
	Node *root;
	Mytree():root(nullptr){}

public:
	bool isempty();
	Node* makeEmpty();
	int size();
	int maxdepth();
	bool print_preorder();
	Node* find(int k);
	Node* findMin();
	Node* findMax();
	bool insert(int k);
	bool mydelete(int k);

private:
	void makeEmpty_helper(Node *node);
	int size_helper(Node *node);
	int maxdepth_helper(Node *node);
	bool print_preorder_helper(Node *node);
	Node* find_helper(Node* node,int k);
	Node* findMin_helper(Node* node);
	Node* findMax_helper(Node* node);
	Node* insert_helper(Node* node, int k);
	Node* mydelete_helper(Node* node, int k);
};


#endif