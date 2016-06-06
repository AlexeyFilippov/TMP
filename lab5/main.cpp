#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Node
{
	int prior;
public:
	Node(int a) : prior(a) {}
	void print() { cout << prior << endl; }
	int get() { return prior; }
};


class Tree
{
	vector<Node*> nodes;
public:
	Tree() {}
	void add(int a)
	{
		Node* node = new Node(a);
		nodes.push_back(node);
		if (nodes.size() > 1) this->up(nodes.size() - 1);
	}
	void up(unsigned p)
	{
		Node* node = nodes.at(p);
		unsigned parpos = floor(p / 2);
		Node* par = nodes.at(parpos);
		if (node->get() < par->get())
		{
			nodes.at(parpos) = node;
			nodes.at(p) = par;
			if (parpos) this->up(parpos);
		}
	}
	void del()
	{
		if (nodes.size() > 0)
		{
			Node* node = nodes.front();
			nodes.erase(nodes.begin());
			delete node;
			if (nodes.size() > 2) this->up(2);
			if (nodes.size() > 1) this->up(1);
		}
		else cout << "Tree is empty!" << endl;
	}
	void print()
	{
		if (nodes.size()) nodes.front()->print();
		else cout << "Tree is empty!" << endl;
	}
	~Tree()
	{
		for (unsigned i = 0; i < nodes.size(); i++) delete nodes.at(i);
		nodes.clear();
	}
};


void handler(Tree* tree, string com)
{
	if (com == "add")
	{
		int a;
		cin >> a;
		tree->add(a);
	}
	else if (com == "del") tree->del();
	else if (com == "get") tree->print();
	else cout << "Invalid command!" << endl;
}


void main()
{
	int n;
	string com;
	Tree* tree = new Tree();
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter commands:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		handler(tree, com);
	}
	system("pause");
}
