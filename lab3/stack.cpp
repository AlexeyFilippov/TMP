#include <iostream>

using namespace std;

struct element
{
	int x;
	element *Next = NULL;
};

class Stack
{
	element *Head;
public:
	Stack() { Head = new element; }
	~Stack();
	void Add(int x);
	void Show();
	void Del();
};

Stack::~Stack()
{
	while (Head != NULL)
	{
		element *temp = Head->Next;
		delete Head;
		Head = temp;
	}
}

void Stack::Add(int x)
{
	element *temp = new element;
	temp->x = x;
	temp->Next = Head;
	Head = temp;

}

void Stack::Show()
{
	cout << Head->x << endl;
}

void Stack::Del()
{
	element *node = Head;
	Head = Head->Next;
	delete node;

}

int main()
{
	int N, val;
	Stack stack;
	string s;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "add") {
			cin >> val;
			stack.Add(val);
		}
		if (s == "del") {
			Stack.Del();
		}
		if (s == "get") {
			stack.Show();
		}

	}

	return 0;
}
