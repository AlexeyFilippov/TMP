#include <iostream>
#include <vector>
using namespace std;


void main()
{
	int V, E, N;
	
	cout << "Enter number of nodes and edges:" << endl;
	cin >> V >> E;
	int **map = new int*[V];
	bool *vis = new bool[V];
	int *min = new int[V];
	for (int k = 0; k < V; k++)
	{
		map[k] = new int[V];
		vis[k] = false;
		min[k] = INT_MAX;
	}
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			map[i][j] = INT_MAX;
	cout << "Enter N:" << endl;
	cin >> N;
	min[N] = 0;

	cout << "Enter edges values:" << endl;
	for (int k = 0; k < E; k++)
	{
		int n1, n2, val;
		cin >> n1 >> n2 >> val;
		map[n1][n2] = val;
	}

	for (int k = 0; k < V; k++)
	{
		int cur;
		int m = INT_MAX;
		for (int g = 0; g < V; g++)
			if ((min[g] < m) && (!vis[g]))
			{
				m = min[g];
				cur = g;
			}
		for (int g = 0; g < V; g++)
			if (map[cur][g] != INT_MAX)
				if ((m + map[cur][g]) < min[g]) min[g] = m + map[cur][g];
		vis[cur] = true;
	}

	for (int k = 0; k < V; k++) cout << min[k] << " ";
	cout << endl;
	system("pause");
}
