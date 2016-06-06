#include "stdafx.h"
#include <iostream>

using namespace std;

int N;
int* inputArray;

void direct(int root) {
	cout << root << " ";

	for (int i = 0; i < N; i++)
		if (inputArray[i] == root)
			direct(i);
}


void back(int root) {
	for (int i = 0; i < N; i++)
		if (inputArray[i] == root)
			back(i);

	cout << root << " ";
}


void symmetric(int root) {
	int id = 0;
	while ((inputArray[id] != root) && (id < N))
		id++;
	if (id < N)
		symmetric(id);

	cout << root << " ";

	if (id < N)
		for (int i = id + 1; i < N; i++)
			if (inputArray[i] == root)
				symmetric(i);
}


int main() {

	cin >> N;
	inputArray = new int[N];
	for (int i = 0; i < N; i++)
		cin >> inputArray[i];

	int root = 0;
	while (inputArray[root] != -1)
		root++;

	direct(root);
	cout << endl;
	back(root);
	cout << endl;
	symmetric(root);
	cout << endl;

	delete[] inputArray;

	return 0;
}
