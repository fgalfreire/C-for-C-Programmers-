// STL implementation of Prim's algorithm for MST
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
   int V;   // No. of vertices

   // In a weighted graph, we need to store vertex
   // and weight pair for every edge
   list<pair<int, int>>* adj;

public:
   Graph( int V );   // Constructor

   // function to add an edge to graph
   void addEdge( int u, int v, int w );

   // Print MST using Prim's algorithm
   void primMST();
};

// Allocates memory for adjacency list
Graph::Graph( int V )
{
   this->V = V;
   adj = new list<iPair>[ V ];
}

void Graph::addEdge( int u, int v, int w )
{
   adj[ u ].push_back( make_pair( v, w ) );
   adj[ v ].push_back( make_pair( u, w ) );
}

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
   // Create a priority queue to store vertices that
   // are being preinMST. This is weird syntax in C++.
   // Refer below link for details of this syntax
   // http://geeksquiz.com/implement-min-heap-using-stl/
   priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

   int src = 0;   // Taking vertex 0 as source

   // Create a vector for keys and initialize all
   // keys as infinite (INF)
   vector<int> key( V, INF );

   // To store parent array which in turn store MST
   vector<int> parent( V, -1 );

   // To keep track of vertices included in MST
   vector<bool> inMST( V, false );

   // Insert source itself in priority queue and initialize
   // its key as 0.
   pq.push( make_pair( 0, src ) );
   key[ src ] = 0;

   /* Looping till priority queue becomes empty */
   while ( !pq.empty() )
   {
      // The first vertex in pair is the minimum key
      // vertex, extract it from priority queue.
      // vertex label is stored in second of pair (it
      // has to be done this way to keep the vertices
      // sorted key (key must be first item
      // in pair)
      int u = pq.top().second;
      pq.pop();

      inMST[ u ] = true;   // Include vertex in MST

      // 'i' is used to get all adjacent vertices of a vertex
      list<pair<int, int>>::iterator i;
      for ( i = adj[ u ].begin(); i != adj[ u ].end(); ++i )
      {
         // Get vertex label and weight of current adjacent
         // of u.
         int v = ( *i ).first;
         int weight = ( *i ).second;

         // If v is not in MST and weight of (u,v) is smaller
         // than current key of v
         if ( inMST[ v ] == false && key[ v ] > weight )
         {
            // Updating key of v
            key[ v ] = weight;
            pq.push( make_pair( key[ v ], v ) );
            parent[ v ] = u;
         }
      }
   }

   // Print edges of MST using parent array
   for ( int i = 1; i < V; ++i )
      printf( "%d - %d\n", parent[ i ], i );
}

// Driver program to test methods of graph class
int main()
{
   // create the graph given in above fugure
   int V = 20;
   Graph g( V );

   // making above shown graph
   g.addEdge( 0, 1, 17 );
   g.addEdge( 0, 2, 2 );
   g.addEdge( 0, 3, 9 );
   g.addEdge( 0, 4, 24 );
   g.addEdge( 0, 5, 28 );
   g.addEdge( 0, 6, 29 );
   g.addEdge( 0, 7, 14 );
   g.addEdge( 0, 8, 28 );
   g.addEdge( 0, 9, 13 );
   g.addEdge( 0, 10, 23 );
   g.addEdge( 0, 11, 10 );
   g.addEdge( 0, 12, 15 );
   g.addEdge( 0, 13, 23 );
   g.addEdge( 0, 14, 15 );
   g.addEdge( 0, 15, 18 );
   g.addEdge( 0, 16, 11 );
   g.addEdge( 0, 17, 4 );
   g.addEdge( 0, 18, 27 );
   g.addEdge( 0, 19, 5 );
   g.addEdge( 1, 0, 17 );
   g.addEdge( 1, 2, 9 );
   g.addEdge( 1, 3, 3 );
   g.addEdge( 1, 5, 14 );
   g.addEdge( 1, 6, 1 );
   g.addEdge( 1, 8, 27 );
   g.addEdge( 1, 9, 20 );
   g.addEdge( 1, 10, 16 );
   g.addEdge( 1, 11, 24 );
   g.addEdge( 1, 12, 29 );
   g.addEdge( 1, 13, 6 );
   g.addEdge( 1, 15, 15 );
   g.addEdge( 1, 16, 20 );
   g.addEdge( 1, 17, 1 );
   g.addEdge( 1, 18, 11 );
   g.addEdge( 1, 19, 9 );
   g.addEdge( 2, 0, 2 );
   g.addEdge( 2, 1, 9 );
   g.addEdge( 2, 3, 21 );
   g.addEdge( 2, 4, 21 );
   g.addEdge( 2, 5, 29 );
   g.addEdge( 2, 6, 13 );
   g.addEdge( 2, 7, 19 );
   g.addEdge( 2, 8, 16 );
   g.addEdge( 2, 9, 1 );
   g.addEdge( 2, 10, 11 );
   g.addEdge( 2, 11, 4 );
   g.addEdge( 2, 12, 12 );
   g.addEdge( 2, 14, 26 );
   g.addEdge( 2, 15, 5 );
   g.addEdge( 2, 16, 25 );
   g.addEdge( 2, 17, 12 );
   g.addEdge( 2, 18, 5 );
   g.addEdge( 2, 19, 24 );
   g.addEdge( 3, 0, 9 );
   g.addEdge( 3, 1, 3 );
   g.addEdge( 3, 2, 21 );
   g.addEdge( 3, 4, 11 );
   g.addEdge( 3, 6, 22 );
   g.addEdge( 3, 7, 22 );
   g.addEdge( 3, 8, 12 );
   g.addEdge( 3, 9, 16 );
   g.addEdge( 3, 11, 2 );
   g.addEdge( 3, 12, 1 );
   g.addEdge( 3, 13, 12 );
   g.addEdge( 3, 15, 14 );
   g.addEdge( 3, 16, 15 );
   g.addEdge( 3, 17, 23 );
   g.addEdge( 3, 18, 27 );
   g.addEdge( 3, 19, 28 );
   g.addEdge( 4, 0, 24 );
   g.addEdge( 4, 2, 21 );
   g.addEdge( 4, 3, 11 );
   g.addEdge( 4, 5, 25 );
   g.addEdge( 4, 7, 1 );
   g.addEdge( 4, 8, 1 );
   g.addEdge( 4, 9, 5 );
   g.addEdge( 4, 11, 24 );
   g.addEdge( 4, 12, 29 );
   g.addEdge( 4, 13, 9 );
   g.addEdge( 4, 14, 4 );
   g.addEdge( 4, 15, 2 );
   g.addEdge( 4, 16, 5 );
   g.addEdge( 4, 18, 10 );
   g.addEdge( 4, 19, 10 );
   g.addEdge( 5, 0, 28 );
   g.addEdge( 5, 1, 14 );
   g.addEdge( 5, 2, 29 );
   g.addEdge( 5, 4, 25 );
   g.addEdge( 5, 6, 1 );
   g.addEdge( 5, 7, 17 );
   g.addEdge( 5, 8, 22 );
   g.addEdge( 5, 9, 7 );
   g.addEdge( 5, 10, 20 );
   g.addEdge( 5, 11, 7 );
   g.addEdge( 5, 12, 22 );
   g.addEdge( 5, 13, 16 );
   g.addEdge( 5, 14, 11 );
   g.addEdge( 5, 15, 22 );
   g.addEdge( 5, 16, 2 );
   g.addEdge( 5, 17, 23 );
   g.addEdge( 5, 18, 1 );
   g.addEdge( 5, 19, 20 );
   g.addEdge( 6, 0, 29 );
   g.addEdge( 6, 1, 1 );
   g.addEdge( 6, 2, 13 );
   g.addEdge( 6, 3, 22 );
   g.addEdge( 6, 5, 1 );
   g.addEdge( 6, 8, 18 );
   g.addEdge( 6, 9, 7 );
   g.addEdge( 6, 11, 4 );
   g.addEdge( 6, 12, 18 );
   g.addEdge( 6, 13, 11 );
   g.addEdge( 6, 14, 14 );
   g.addEdge( 6, 15, 5 );
   g.addEdge( 6, 16, 24 );
   g.addEdge( 6, 17, 5 );
   g.addEdge( 6, 18, 13 );
   g.addEdge( 7, 0, 14 );
   g.addEdge( 7, 2, 19 );
   g.addEdge( 7, 3, 22 );
   g.addEdge( 7, 4, 1 );
   g.addEdge( 7, 5, 17 );
   g.addEdge( 7, 8, 27 );
   g.addEdge( 7, 9, 7 );
   g.addEdge( 7, 10, 2 );
   g.addEdge( 7, 11, 5 );
   g.addEdge( 7, 13, 29 );
   g.addEdge( 7, 14, 16 );
   g.addEdge( 7, 15, 25 );
   g.addEdge( 7, 16, 8 );
   g.addEdge( 7, 17, 19 );
   g.addEdge( 7, 18, 26 );
   g.addEdge( 7, 19, 23 );
   g.addEdge( 8, 0, 28 );
   g.addEdge( 8, 1, 27 );
   g.addEdge( 8, 2, 16 );
   g.addEdge( 8, 3, 12 );
   g.addEdge( 8, 4, 1 );
   g.addEdge( 8, 5, 22 );
   g.addEdge( 8, 6, 18 );
   g.addEdge( 8, 7, 27 );
   g.addEdge( 8, 9, 3 );
   g.addEdge( 8, 10, 3 );
   g.addEdge( 8, 11, 26 );
   g.addEdge( 8, 12, 9 );
   g.addEdge( 8, 13, 25 );
   g.addEdge( 8, 14, 16 );
   g.addEdge( 8, 15, 7 );
   g.addEdge( 8, 16, 4 );
   g.addEdge( 8, 17, 23 );
   g.addEdge( 8, 18, 7 );
   g.addEdge( 9, 0, 13 );
   g.addEdge( 9, 1, 20 );
   g.addEdge( 9, 2, 1 );
   g.addEdge( 9, 3, 16 );
   g.addEdge( 9, 4, 5 );
   g.addEdge( 9, 5, 7 );
   g.addEdge( 9, 6, 7 );
   g.addEdge( 9, 7, 7 );
   g.addEdge( 9, 8, 3 );
   g.addEdge( 9, 11, 23 );
   g.addEdge( 9, 12, 3 );
   g.addEdge( 9, 13, 3 );
   g.addEdge( 9, 14, 28 );
   g.addEdge( 9, 15, 24 );
   g.addEdge( 9, 16, 12 );
   g.addEdge( 9, 17, 20 );
   g.addEdge( 9, 18, 25 );
   g.addEdge( 9, 19, 25 );
   g.addEdge( 10, 0, 23 );
   g.addEdge( 10, 1, 16 );
   g.addEdge( 10, 2, 11 );
   g.addEdge( 10, 5, 20 );
   g.addEdge( 10, 7, 2 );
   g.addEdge( 10, 8, 3 );
   g.addEdge( 10, 12, 27 );
   g.addEdge( 10, 13, 13 );
   g.addEdge( 10, 14, 25 );
   g.addEdge( 10, 15, 2 );
   g.addEdge( 10, 16, 3 );
   g.addEdge( 10, 17, 4 );
   g.addEdge( 10, 18, 4 );
   g.addEdge( 10, 19, 15 );
   g.addEdge( 11, 0, 10 );
   g.addEdge( 11, 1, 24 );
   g.addEdge( 11, 2, 4 );
   g.addEdge( 11, 3, 22 );
   g.addEdge( 11, 4, 24 );
   g.addEdge( 11, 5, 7 );
   g.addEdge( 11, 6, 4 );
   g.addEdge( 11, 7, 5 );
   g.addEdge( 11, 8, 26 );
   g.addEdge( 11, 9, 23 );
   g.addEdge( 11, 12, 1 );
   g.addEdge( 11, 14, 1 );
   g.addEdge( 11, 15, 20 );
   g.addEdge( 11, 16, 20 );
   g.addEdge( 11, 17, 22 );
   g.addEdge( 11, 18, 19 );
   g.addEdge( 11, 19, 28 );
   g.addEdge( 12, 0, 15 );
   g.addEdge( 12, 1, 29 );
   g.addEdge( 12, 2, 12 );
   g.addEdge( 12, 3, 1 );
   g.addEdge( 12, 4, 29 );
   g.addEdge( 12, 5, 22 );
   g.addEdge( 12, 6, 18 );
   g.addEdge( 12, 8, 9 );
   g.addEdge( 12, 9, 3 );
   g.addEdge( 12, 10, 27 );
   g.addEdge( 12, 11, 1 );
   g.addEdge( 12, 13, 23 );
   g.addEdge( 12, 14, 6 );
   g.addEdge( 12, 15, 9 );
   g.addEdge( 12, 16, 28 );
   g.addEdge( 12, 17, 1 );
   g.addEdge( 12, 18, 6 );
   g.addEdge( 12, 19, 13 );
   g.addEdge( 13, 0, 23 );
   g.addEdge( 13, 1, 6 );
   g.addEdge( 13, 3, 12 );
   g.addEdge( 13, 4, 9 );
   g.addEdge( 13, 5, 16 );
   g.addEdge( 13, 6, 11 );
   g.addEdge( 13, 7, 29 );
   g.addEdge( 13, 8, 25 );
   g.addEdge( 13, 9, 3 );
   g.addEdge( 13, 10, 13 );
   g.addEdge( 13, 12, 23 );
   g.addEdge( 13, 14, 5 );
   g.addEdge( 13, 15, 19 );
   g.addEdge( 13, 16, 18 );
   g.addEdge( 13, 17, 4 );
   g.addEdge( 13, 18, 16 );
   g.addEdge( 13, 19, 12 );
   g.addEdge( 14, 0, 15 );
   g.addEdge( 14, 2, 26 );
   g.addEdge( 14, 4, 4 );
   g.addEdge( 14, 5, 11 );
   g.addEdge( 14, 6, 14 );
   g.addEdge( 14, 7, 16 );
   g.addEdge( 14, 8, 16 );
   g.addEdge( 14, 9, 28 );
   g.addEdge( 14, 10, 25 );
   g.addEdge( 14, 11, 1 );
   g.addEdge( 14, 12, 6 );
   g.addEdge( 14, 13, 5 );
   g.addEdge( 14, 15, 6 );
   g.addEdge( 14, 16, 27 );
   g.addEdge( 14, 17, 15 );
   g.addEdge( 14, 18, 1 );
   g.addEdge( 14, 19, 28 );
   g.addEdge( 15, 0, 18 );
   g.addEdge( 15, 1, 15 );
   g.addEdge( 15, 2, 5 );
   g.addEdge( 15, 3, 14 );
   g.addEdge( 15, 4, 2 );
   g.addEdge( 15, 5, 22 );
   g.addEdge( 15, 6, 5 );
   g.addEdge( 15, 7, 25 );
   g.addEdge( 15, 8, 7 );
   g.addEdge( 15, 9, 24 );
   g.addEdge( 15, 10, 2 );
   g.addEdge( 15, 11, 20 );
   g.addEdge( 15, 12, 9 );
   g.addEdge( 15, 13, 19 );
   g.addEdge( 15, 14, 6 );
   g.addEdge( 15, 16, 23 );
   g.addEdge( 15, 17, 21 );
   g.addEdge( 15, 18, 28 );
   g.addEdge( 15, 19, 2 );
   g.addEdge( 16, 0, 11 );
   g.addEdge( 16, 1, 20 );
   g.addEdge( 16, 2, 25 );
   g.addEdge( 16, 3, 15 );
   g.addEdge( 16, 4, 5 );
   g.addEdge( 16, 5, 2 );
   g.addEdge( 16, 6, 24 );
   g.addEdge( 16, 7, 8 );
   g.addEdge( 16, 8, 4 );
   g.addEdge( 16, 9, 12 );
   g.addEdge( 16, 10, 3 );
   g.addEdge( 16, 11, 20 );
   g.addEdge( 16, 12, 28 );
   g.addEdge( 16, 13, 18 );
   g.addEdge( 16, 14, 27 );
   g.addEdge( 16, 15, 23 );
   g.addEdge( 16, 17, 9 );
   g.addEdge( 16, 18, 11 );
   g.addEdge( 16, 19, 12 );
   g.addEdge( 17, 0, 4 );
   g.addEdge( 17, 1, 1 );
   g.addEdge( 17, 2, 12 );
   g.addEdge( 17, 3, 23 );
   g.addEdge( 17, 5, 23 );
   g.addEdge( 17, 6, 5 );
   g.addEdge( 17, 7, 19 );
   g.addEdge( 17, 8, 23 );
   g.addEdge( 17, 9, 20 );
   g.addEdge( 17, 10, 4 );
   g.addEdge( 17, 11, 22 );
   g.addEdge( 17, 12, 1 );
   g.addEdge( 17, 13, 4 );
   g.addEdge( 17, 14, 15 );
   g.addEdge( 17, 15, 21 );
   g.addEdge( 17, 16, 9 );
   g.addEdge( 17, 18, 20 );
   g.addEdge( 17, 19, 9 );
   g.addEdge( 18, 0, 27 );
   g.addEdge( 18, 1, 11 );
   g.addEdge( 18, 2, 5 );
   g.addEdge( 18, 3, 27 );
   g.addEdge( 18, 4, 10 );
   g.addEdge( 18, 5, 1 );
   g.addEdge( 18, 6, 13 );
   g.addEdge( 18, 7, 26 );
   g.addEdge( 18, 8, 7 );
   g.addEdge( 18, 9, 25 );
   g.addEdge( 18, 10, 4 );
   g.addEdge( 18, 11, 19 );
   g.addEdge( 18, 12, 6 );
   g.addEdge( 18, 13, 16 );
   g.addEdge( 18, 14, 1 );
   g.addEdge( 18, 15, 28 );
   g.addEdge( 18, 16, 11 );
   g.addEdge( 18, 17, 20 );
   g.addEdge( 18, 19, 11 );
   g.addEdge( 19, 0, 5 );
   g.addEdge( 19, 1, 9 );
   g.addEdge( 19, 2, 24 );
   g.addEdge( 19, 3, 28 );
   g.addEdge( 19, 4, 10 );
   g.addEdge( 19, 5, 20 );
   g.addEdge( 19, 7, 23 );
   g.addEdge( 19, 9, 25 );
   g.addEdge( 19, 10, 15 );
   g.addEdge( 19, 11, 28 );
   g.addEdge( 19, 12, 13 );
   g.addEdge( 19, 13, 12 );
   g.addEdge( 19, 14, 28 );
   g.addEdge( 19, 15, 2 );
   g.addEdge( 19, 16, 12 );
   g.addEdge( 19, 17, 9 );

   g.addEdge( 19, 18, 11 );
   g.primMST();

   return 0;
}
