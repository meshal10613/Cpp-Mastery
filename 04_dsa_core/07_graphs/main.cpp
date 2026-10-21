#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//? DSA CORE (07. GRAPHS: BFS, DFS & DIJKSTRA'S ALGORITHM)
//* A Graph is a non-linear data structure consisting of Vertices (V) and Edges (E).
//*
//* Representation:
//* - Adjacency List: vector<vector<int>> or vector<vector<pair<int, int>>> (Weighted)
//*
//* Traversal & Shortest Path:
//* 1. BFS: Queue-based, explores layer by layer. Guarantees shortest path in unweighted graphs.
//* 2. DFS: Recursion/Stack-based, explores deep along each branch.
//* 3. Dijkstra's Algorithm: Priority Queue-based, solves Single-Source Shortest Path in weighted graphs.

// 1. Breadth-First Search (BFS)
void bfs(int startNode, const vector<vector<int>> &adj)
{
	int n = adj.size();
	vector<bool> visited(n, false);
	queue<int> q;

	visited[startNode] = true;
	q.push(startNode);

	cout << "BFS Traversal from Node " << startNode << ": ";
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int neighbor : adj[node])
		{
			if (!visited[neighbor])
			{
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
	cout << "\n";
}

// 2. Dijkstra's Shortest Path Algorithm
vector<int> dijkstra(int startNode, int n, const vector<vector<pair<int, int>>> &weightedAdj)
{
	const int INF = 1e9;
	vector<int> dist(n, INF);
	// Min-heap storing {distance, node}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[startNode] = 0;
	pq.push({0, startNode});

	while (!pq.empty())
	{
		auto [currentDist, u] = pq.top();
		pq.pop();

		if (currentDist > dist[u]) continue; // Skip outdated paths

		for (const auto &[v, weight] : weightedAdj[u])
		{
			if (dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

int main()
{
	cout << "====================================================\n";
	cout << " 07. DSA CORE: GRAPHS (BFS & DIJKSTRA)              \n";
	cout << "====================================================\n\n";

	// Unweighted Graph Demo (5 nodes: 0, 1, 2, 3, 4)
	int n = 5;
	vector<vector<int>> adj(n);
	adj[0] = {1, 2};
	adj[1] = {0, 3};
	adj[2] = {0, 4};
	adj[3] = {1};
	adj[4] = {2};

	bfs(0, adj);

	// Weighted Graph Demo for Dijkstra
	// 0 -> (1 with weight 4), (2 with weight 1)
	// 2 -> (1 with weight 2), (3 with weight 5)
	// 1 -> (3 with weight 1)
	int numNodes = 4;
	vector<vector<pair<int, int>>> weightedAdj(numNodes);
	weightedAdj[0].push_back({1, 4});
	weightedAdj[0].push_back({2, 1});
	weightedAdj[2].push_back({1, 2});
	weightedAdj[2].push_back({3, 5});
	weightedAdj[1].push_back({3, 1});

	vector<int> shortestDistances = dijkstra(0, numNodes, weightedAdj);

	cout << "\n--- Dijkstra Shortest Distances from Node 0 ---\n";
	for (int i = 0; i < numNodes; i++)
	{
		cout << "To Node " << i << " : " << shortestDistances[i] << " units\n";
	}

	return 0;
}

