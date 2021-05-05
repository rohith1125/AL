//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//BFS

#include <bits/stdc++.h>
using namespace std;

int c;

void bfs(int **adj, bool *visited, int n, int startVertex)
{
	c++;
	queue<int> q;
	c++;
	q.push(startVertex);
	//visited[startVertex] = true;
	c++;
	while(!q.empty())
	{
		c++;
		int p = q.front();
		c++;
		cout << p << "\t";
		c++;
		q.pop();
		for(int i = 0 ; i < n ; i++, c++)
		{
			c++;
			if(adj[p][i] == 1 && !visited[i])
			{
				visited[i] = true;
				c++;
				q.push(i);
			}

		}
	}
}

int main()
{
	c++;
	int v, e;
	c++;
	cout<<"enter number of vertices and edges respectively"<<endl;
	cin >> v >> e;
	c++;
	cout << endl;

	int **adj = new int*[v];
	for(int i = 0 ; i < v ; i++, c++)
		adj[i] = new int[v];

	for(int i = 0 ; i < v ; i++, c++)
		for(int j = 0 ; j < v ;j++, c++)
			adj[i][j] = 0;


	for(int i = 0 ; i < e ; i++, c++)
	{
		c++;
		int l, r;
		c++;
		cin >> l >> r;
		c++;
		adj[l][r] = 1;
		adj[r][l] = 1;
	}

	bool *visited = new bool[v];
	for(int i = 0 ; i < v ; i++, c++)
		visited[i] = false;

	c++;
	int startVertex;
	c++;
	cout << "Enter start vertex: ";
	c++;
	cin >> startVertex;
	c++;
	visited[startVertex] = true;
	c++;
	bfs(adj, visited, v, startVertex);

	cout << "\nStep count: " << c;
	
	return 0;
}