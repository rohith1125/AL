//Created by Sai Rohith on 2021-06-04
//Copyright © 2021 Sai Rohith. All rights reserved.

//Shortest Pairs
#include <iostream>
using namespace std;
int c = 0;
int V;
void ShortestPair(int graph[][10])
{
 c++;
 int dist[V][V], i, j, k;
 for (i = 0; i < V; i++)
 for (j = 0; j < V; j++)
 {
 c++;
 dist[i][j] = graph[i][j];
 }
 for (k = 0; k < V; k++)
 for (i = 0; i < V; i++)
 for (j = 0; j < V; j++)
 {
 c++;
 if (dist[i][k] + dist[k][j] < dist[i][j])
 {
 c++;
 dist[i][j] = dist[i][k] + dist[k][j];
 }
 }
 cout << "Shortest pair distance matrix: \n";
 for (int i = 0; i < V; i++)
 {
 for (int j = 0; j < V; j++)
 {
 c++;
 if (i == j)
 {
 c++;
 cout << "0"
 << " ";
 }
 else if (dist[i][j] == 9999)
 {
 cout << "infinity"
 << " ";
 c++;
 }
 else
 {
 c++;
 cout << dist[i][j] << " ";
 }
 }
 cout << endl;
 }
}
int main()
{
 int e;
 cout << "Enter number of vertices and edges ";
 cin >> V >> e;
 int graph[V][10];
 for (int i = 0; i < V; i++)
 {
 for (int j = 0; j < V; j++)
 graph[i][j] = 9999;
 }
 int source, dest, cost;
 cout << "Enter source ,destination and cost of each edge\n";
 for (int i = 0; i < e; i++)
 {
 cin >> source >> dest >> cost;
 graph[--source][--dest] = cost;
 }
 ShortestPair(graph);
 cout << "Step count " << c << endl;
 return 0;
}