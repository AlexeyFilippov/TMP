#include <iostream>

using namespace std;

struct element {
	int x;
	element *Next = NULL;
};

class List {
	element *Head;
public:
	List() { Head = new element; }
	~List();
	void Add(int x, int ind);
	void Show(int);
	void Del(int);
};

List::~List() {
	while (Head != NULL) {
		element *temp = Head->Next;
		delete Head;
		Head = temp;
	}
}

void List::Add(int x, int ind) {
	element *temp = new element;
	temp->x = x;
	if (ind == 0) {
		temp->Next = Head;
		Head = temp;
	}
	else {
		element *node = Head;
		if (ind > 1) {
			for (int i = 0; i < ind - 1; i++) {
				if (node->Next != NULL)
					node = node->Next;
				else {
					element *empty = new element;
					node->Next = empty;
					node = node->Next;
				}
			}
		}

		element *tempElem = node->Next;
		node->Next = temp;
		temp->Next = tempElem;
	}

}

void List::Show(int ind) {
	element *temp = Head;
	if (ind != 0) {
		for (int i = 0; i < ind; i++)
		{
			temp = temp->Next;
		}
	}
	cout << temp->x << endl;
}

void List::Del(int ind) {
	if (ind == 0) Head = Head->Next;
	else {
		element *temp = Head;
		if (ind > 1) {
			for (int i = 0; i < ind - 1; i++)
			{
				temp = temp->Next;
			}
		}
		element *node = temp->Next;
		temp->Next = node->Next;
		delete node;
	}
}

int main() {
	int N, ind, val;
	List lst;
	string s;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "add") {
			cin >> ind >> val;
			lst.Add(ind, val);
		}

		if (s == "del") {
			cin >> ind;
			lst.Del(ind);
		}

		if (s == "get") {
			cin >> ind;
			lst.Show(ind);
		}
	}
	return 0;
}
