
// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 
#include<iostream>
#include<bits/stdc++.h>
#include <limits.h> 
#include <stdio.h> 
 
using namespace std;


int V;  
// Number of vertices in the graph 
//#define V 9 
//////////////////////////////////////////////////////////////////////////////////////////
// A Class to represent directed graph 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // adj[u][v] would be true if there is an edge 
    // from u to v, else false 
    int **adj; 
  
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v, int cost )  { adj[u][v] = cost; } 
    void print(); 
    int getCost(int u, int v);
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
  
    // Create a dynamic array of pointers 
    adj = new int* [V]; 
  
    // Create a row for every pointer 
    for (int i=0; i<V; i++) 
    { 
       // Note : Rows may not be contiguous 
       adj[i] = new int[V]; 
  
       // Initialize all entries as false to indicate 
       // that there are no edges initially 
       memset(adj[i], false, V*sizeof(int)); 
    } 
} 
  
// Utility method to print adjacency matrix 
void Graph::print() 
{ 
   for (int u=0; u<V; u++) 
   { 
      for (int v=0; v<V; v++) 
         {cout << adj[u][v] << " ";}
      cout << endl; 
   } 
}

int Graph::getCost(int u, int v)
{ return adj[u][v];}

/////////////////////////////////////////////////////////////////////////////////////////

  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// A utility function to print the constructed distance array 
void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(Graph g, int src) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && g.getCost(u,v) && dist[u] != INT_MAX 
                && dist[u] + g.getCost(u,v) < dist[v]) 
                dist[v] = dist[u] + g.getCost(u,v); 
    } 
  
    // print the constructed distance array 
    printSolution(dist); 
} 
  
// driver program to test above function 
int main() 
{   
    cout << "How many vertices: " << endl;
    cin >> V;
    Graph g(V); 
    for (int i = 0;i<V;i++)
    {   int cost = 0;
        for(int j = 0;j<V;j++)
        {
            cout << "Add cost between vertex " << i << " and " << j << " : ";
            cin >> cost;
            g.addEdge(i,j,cost);
        }
        cout << "__________________________________"<< endl;
    }
  
    g.print(); 
  
    dijkstra(g, 0); 
  
    return 0; 
}
