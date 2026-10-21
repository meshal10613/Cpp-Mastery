#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

//? PROJECT 04: GPS ROUTE NAVIGATION ENGINE (STARTER SKELETON)
//* Follow the TODOs below to implement your GPS router!

struct Point2D
{
	double x, y;
};

struct Edge
{
	int to;
	double distance; // in km
	double speedLimit; // in km/h
};

struct LocationNode
{
	int id;
	string name;
	Point2D coord;
	vector<Edge> neighbors;
};

class NavigationEngine
{
private:
	vector<LocationNode> graph;

public:
	// Calculate Euclidean distance heuristic for A*
	double calculateHeuristic(int fromNode, int toNode) const
	{
		double dx = graph[fromNode].coord.x - graph[toNode].coord.x;
		double dy = graph[fromNode].coord.y - graph[toNode].coord.y;
		return sqrt(dx * dx + dy * dy);
	}

	// TODO: Step 1 - Add node to road network
	void addNode(int id, const string &name, double x, double y)
	{
		LocationNode node{id, name, {x, y}, {}};
		if (id >= (int)graph.size()) graph.resize(id + 1);
		graph[id] = node;
	}

	// TODO: Step 2 - Add road connection between two nodes
	void addRoad(int from, int to, double distance, double speedLimit)
	{
		graph[from].neighbors.push_back({to, distance, speedLimit});
		graph[to].neighbors.push_back({from, distance, speedLimit}); // Bidirectional
	}

	// TODO: Step 3 - Implement Dijkstra's Algorithm
	vector<int> findShortestPathDijkstra(int startNode, int endNode)
	{
		vector<int> path;
		// TODO: Implement Dijkstra priority queue logic
		return path;
	}

	// TODO: Step 4 - Implement A* Search Algorithm with Heuristic
	vector<int> findShortestPathAStar(int startNode, int endNode)
	{
		vector<int> path;
		// TODO: Implement A* search logic using calculateHeuristic
		return path;
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " PROJECT 04: GPS ROUTE NAVIGATION SKELETON          \n";
	cout << "====================================================\n\n";

	NavigationEngine nav;
	cout << "Ready for implementation! Follow the instructions in README.md.\n";

	return 0;
}

