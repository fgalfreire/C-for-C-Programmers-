/*
Author: Galán Fernando
File: Algortihm.hpp

Just the definition of a Graph, I did implemented here some getters as they
were straightforward
*/
#include <vector>

class Graph
{
private:
   int aNumVert;
   int aNumEdges;
   std::vector<std::vector<int>> aAdjMtr;

public:
   Graph(){};
   Graph( int aNumVert );
   Graph( int aNumVert, double aDensity );

   int getEdgesNum()
   {
      return aNumEdges;
   }
   int getVerticesNum()
   {
      return aNumVert;
   }
   std::vector<std::vector<int>> getAdjMatrix()
   {
      return aAdjMtr;
   }
   std::vector<int> getVertices();
   std::vector<int> getNeighbors( int& aX );
   int getEdgeVal( int aX, int aY );

   bool setEdgeVal( int aX, int aY, int aWeight );

   bool isAdyacent( int aX, int aY );
   bool delEdge( int aX, int aY );
   bool addEdge( int aX, int aY, int aVal );

   void printMatrix();

   //~aGraph();
};
