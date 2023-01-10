#include <iostream>

// #include "Data.h"

using namespace std;



int main()

{

	int ch;

	Graph g(8);

	cout << "Graph Operations" << endl;

	cout << "[1] Adjacency List" << endl;

	cout << "[2] Adjacency Matrix" << endl;

	cout << "Enter choice: ";

	cin >> ch;

	if (ch == 1)

	{

		g.addEdge(0, 6);

		g.addEdge(1, 5);

		g.addEdge(2, 0);

		g.addEdge(2, 4);

		g.addEdge(3, 5);

		g.addEdge(4, 1);

		g.addEdge(4, 3);

		g.addEdge(5, 7);

		g.addEdge(6, 1);

		g.addEdge(6, 7);

		g.printGraph();

		cout << endl << "DFS Traversal..." << endl;

		g.DFS(1);

		cout << endl << endl;

		cout << endl << "BFS Traversal..." << endl;

		g.BFS(3);

	}

	else if (ch == 2)

	{

		g.addEdge2(0, 6);

		g.addEdge2(1, 5);

		g.addEdge2(2, 0);

		g.addEdge2(2, 4);

		g.addEdge2(3, 5);

		g.addEdge2(4, 1);

		g.addEdge2(4, 3);

		g.addEdge2(5, 7);

		g.addEdge2(6, 1);

		g.addEdge2(6, 7);

		g.printGraph2();

	}

	cout << endl << endl;

}



//Data.h

#pragma once

#include <list>

#include <iostream>

using namespace std;



class Graph

{

private:

	int V;

	list <int> *adj;						      //Programmer2

	int **adj2;								       //Programmer2

	void DFSUtil(int v, bool visited[]);	 //Lead

	void BFSUtil(int s, bool visited[]);	 //Lead



 public:

	Graph(int);								    //All	

	void addEdge(int u, int v);				//All

	void addEdge2(int u, int v);			//Programmer2

	void printGraph();						  //All

	void printGraph2();						  //Programmer2

	void DFS(int v);						   //Lead

	void BFS(int s);						   //Lead

};



//Implementation.h

#include <iostream>

#include <list>

#include "Data.h"

using namespace std;



Graph::Graph(int x)

{

	V = x;

	adj = new list <int> [V];

	adj2 = new int* [V];

	for (int i = 0; i < V; i++)

			adj2[i] = new int[V];

	for (int i = 0; i < V; i++)

		for (int j = 0; j < V; j++)

			adj2[i][j] = 0;



}



void Graph::addEdge(int u, int v)

{

	adj[u].push_back(v);

}



void Graph::addEdge2(int u, int v)

{

	adj2[u][v] = 1;

}



// A utility function to print the adjacency list 

// representation of graph 

void Graph::printGraph()

{

	cout << "Adjacency List..." << endl;

	for (int v = 0; v < V; ++v)

	{

		cout << "V[" << v << "]";

		for (auto x : adj[v])

			cout << " -> " << x;

		cout << endl;

	}

}



void Graph::printGraph2()

{

	cout << "Adjacency Matrix..." << endl << endl;

	cout << "t";

	for (int i = 0; i < V; i++)

		cout << "V[" << i << "]" << "t";

	cout << endl;

	for (int i=0; i<V; i++)

	{

		cout << "V[" << i << "]" << "t";

		for (int j = 0; j < V; j++)

			cout << adj2[i][j] << "t";

		cout << endl;

	}

	cout << endl;

}



void Graph::DFSUtil(int v, bool visited[])

{

	// Mark the current node as visited and 

	// print it 

	visited[v] = true;

	cout << v << " ";



	// Recur for all the vertices adjacent 

	// to this vertex 

	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); ++i)

		if (!visited[*i])

			DFSUtil(*i, visited);

}



// DFS traversal of the vertices reachable from v. 

// It uses recursive DFSUtil() 

void Graph::DFS(int v)

{

	// Mark all the vertices as not visited 

	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)

		visited[i] = false;



	// Call the recursive helper function 

	// to print DFS traversal 

	

	DFSUtil(v, visited);

	for(int i=0; i< V; i++)

		if (!visited[i])

			DFSUtil(i, visited);



	for (int i = 0; i < V; i++)

		if (!visited[i])

			cout << i << " ";

}



void Graph::BFS(int s)

{

	// Mark all the vertices as not visited 

	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)

		visited[i] = false;



	BFSUtil(s, visited);

	for (int i = 0; i < V; i++)

		if (!visited[i])

			BFSUtil(i, visited);



	for (int i = 0; i < V; i++)

		if (!visited[i])

			cout << i << " ";

}



void Graph::BFSUtil(int s, bool visited[])

{

	// Create a queue for BFS 

	list<int> queue;



	// Mark the current node as visited and enqueue it 

	visited[s] = true;

	queue.push_back(s);



	// 'i' will be used to get all adjacent 

	// vertices of a vertex 

	list<int>::iterator i;



	while (!queue.empty())

	{

		// Dequeue a vertex from queue and print it 

		s = queue.front();

		cout << s << " ";

		queue.pop_front();



		// Get all adjacent vertices of the dequeued 

		// vertex s. If a adjacent has not been visited,  

		// then mark it visited and enqueue it 

		for (i = adj[s].begin(); i != adj[s].end(); ++i)

		{

			if (!visited[*i])

			{

				visited[*i] = true;

				queue.push_back(*i);

			}

		}

	}

}