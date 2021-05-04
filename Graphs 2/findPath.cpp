//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Find Path

#include <bits/stdc++.h>
using namespace std;

int c;

void dfs(int **adj, bool *visited, int n, int startVertex, int *parent)
{
	c++;
	visited[startVertex] = true;
		
	for(int i = 0 ; i < n ; i++, c++)
		if(adj[startVertex][i] == 1 && !visited[i])
		{
			c++;
			parent[i] = startVertex;
			dfs(adj, visited, n, i, parent);
		}

}

int main()
{
	int v, e;
	cout << "enter number of vertices and edges respectively"<<endl;
	cin >> v >> e;
	cout << endl;
	c = 0;
	c++;


	int **adj = new int*[v];
	c++;

	for(int i = 0 ; i < v ; i++, c++)
		adj[i] = new int[v];

		for(int i = 0 ; i < v ; i++, c++)
			for(int j = 0 ; j < v ;j++, c++)
				adj[i][j] = 0;


			for(int i = 0 ; i < e ; i++, c++)
			{
				c++;
				int l, r;
				cout << "enter the extremities of the edge"<<endl;
				cin >> l >> r;
				adj[l][r] = 1;
			}

			bool *visited = new bool[v];
			for(int i = 0 ; i < v ; i++, c++)
				visited[i] = false;

			int *parent = new int[v];
			for (int i = 0; i < v; i++, c++)
				parent[i] = i;

			c++;
			int startVertex, endVertex;
			cout << "Enter vertex between which path is to be found: ";
			cin >> startVertex >> endVertex;


			dfs(adj, visited, v, startVertex, parent);

			if(!visited[endVertex])
				cout << "No path exists";
			else
			{
				c++;
				stack<int> s;
				while(parent[endVertex] != endVertex)
				{
					c++;
					s.push(endVertex);
					endVertex = parent[endVertex];
				}

				c++;
				s.push(endVertex);

				while(!s.empty())
				{
					c++;
					cout << s.top();
					if(s.size() != 1)
						cout << " -> ";
					s.pop();
				}
				c++;
			}


			cout << "\nStep count: " << c;

			return 0;
}


/*

5 5

0 1
1 2
2 4
2 3
4 0

Find the vertices between which path is to be found: 4 1
Path: 4 -> 0 -> 1


5 5

0 1
1 2
2 4
2 3
4 0

Find the vertices between which path is to be found: 3 0
No path found between 3 and 0
*/