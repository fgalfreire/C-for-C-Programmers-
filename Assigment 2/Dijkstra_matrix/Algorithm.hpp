/*
Author: Galán Fernando
File: Algortihm.hpp

I defined the class Algorithm and also implemented the behavior of the
comparator which will be used later on the priority queue

*/

#include <limits>

#include "Graph.hpp"

const int aINF = 10000000;

class Algorithm
{
public:
   int Dijkstra( Graph& aG, int aSrc, int aDst );

   //~Algorithm();
};

// The compartor admits pairs from the PQ, as the second member its the cost
// between nodes we comparate them

class MyComparator
{
public:
   int operator()( std::pair<int, int>& aPair1, std::pair<int, int>& aPair2 )
   {
      return aPair1.second > aPair2.second;
   }
};
