//Created by Sai Rohith on 2021-05-18
//Copyright © 2021 Sai Rohith. All rights reserved.

//Topological Sort
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int v, e;
	cin >> v >> e;
	cout << endl;

	int **adj = new int*[v];

	for(int i = 0 ; i < v ; i++)
		adj[i] = new int[v];

	for(int i = 0 ; i < v ; i++)
		for(int j = 0 ; j < v ;j++)
			adj[i][j] = 0;


	for(int i = 0 ; i < e ; i++)
	{
		int l, r;
		cout <<"Enter extremities of the edges sequentially"<<endl;
		cin >> l >> r;
		adj[l][r] = 1;
	}

	int indegree[v]{0};

	for(int j = 0 ; j < v ; j++)
		for(int i = 0 ; i < v ; i++)
			indegree[j] += adj[i][j];


	queue<int> q;
	for(int i = 0 ; i < v ; i++)
		if(indegree[i] == 0)
			q.push(i);

	for(int i = 0 ; i < v ; i++)
		cout << indegree[i] << " ";

	cout << "Topologigcal Order: ";
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for(int i = 0 ; i < v ; i++)
			if(adj[curr][i] == 1)
			{
				indegree[i]--;
				if(indegree[i] == 0)
					q.push(i);
			}

	}

	return 0;
}