//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Find Cycle

#include <bits/stdc++.h>
using namespace std;

int c;

bool hasCycle(int **adj, bool *visited, int n, int startVertex)
{
	visited[startVertex] =  true;
	c++;


	for(int i = 0 ; i < n ; i++, c++)
		if(adj[startVertex][i] == 1)
		{
			c++;
			if(visited[i])
				return true;
			else
				return hasCycle(adj, visited, n, i);
			c++;
		}
		c++;
		return false;
		
		
}

int main()
{
	int v, e;
	cin >> v >> e;
	cout << endl;

	c = 0;
	c++;

	int **adj = new int*[v];

	for(int i = 0 ; i < v ; i++)
		adj[i] = new int[v];

		for(int i = 0 ; i < v ; i++, c++)
			for(int j = 0 ; j < v ;j++, c++)
				adj[i][j] = 0;


			for(int i = 0 ; i < e ; i++, c++)
			{
				c++;
				int l, r;
				cin >> l >> r;
				adj[l][r] = 1;
			}

			bool *visited = new bool[v];
			for(int i = 0 ; i < v ; i++, c++)
				visited[i] = false;

			c++;
			int startVertex;
			c++;
			c++;


			for(int i = 0 ; i < v ; i++)
			{
				bool ans = hasCycle(adj, visited, v, i);
				if(ans)
				{

					cout << "Cycle exists";
					cout << "\nStep count: " << c;
					return 0;
				}

				for(int j = 0 ; j < v ; j++)
					visited[j] = false;


			}

			cout << "No cycle";
			c++;
			cout << "\nStep count: " << c;

			return 0;
}
