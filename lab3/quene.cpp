#include <iostream>

using namespace std;

struct element
{
	int x;
	element *Next = NULL;
};

class Queue
{
	element *Head;
public:
	Queue() { Head = NULL; }
	~Queue();
	void Add(int x);
	void Show();
	void Del();
};

Queue::~Queue()
{
	while (Head != NULL)
	{
		element *temp = Head->Next;
		delete Head;
		Head = temp;
	}
}

void Queue::Add(int x)
{
	element *temp = new element;
	temp->x = x;
	if (Head == NULL) Head = temp;
	else {
		element *node = Head;
		while (node->Next != NULL)
			node = node->Next;
		node->Next = temp;
	}
}

void Queue::Show()
{
	cout << Head->x << endl;
}

void Queue::Del()
{
	Head = Head->Next;

}

int main()
{
	int N, val;
	Queue queue;
	string s;

	cin >> N;
	for (int i = 1; i <= N; i++) {

		cin >> s;
		if (s == "add") {
			cin >> val;
			queue.Add(val);
		}
		if (s == "del") {
			cin >> val;
			queue.Del();
		}
		if (s == "get") {
			cin >> val;
			queue.Show();
		}

	}

	return 0;
}
