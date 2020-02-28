/*
Author: Galán Fernando
File: Algortihm.cpp

In this file I implemented Dijkstras' algorithm using a priority queue from
STL library, this eases the work as we don't really need a specific class, but
I endend implementing an aditional Class named Compartor which purpose is
comparing the cost within the queue.

*/
#include "Algorithm.hpp"

#include <iostream>
#include <queue>

int Algorithm::Dijkstra( Graph& aG, const int aSrc, int aDst )
{
   std::priority_queue<
      std::pair<int, int>,
      std::vector<std::pair<int, int>>,
      MyComparator>
      aPq;   // Priority queue it's compose of two components inside a pair,
             // the fist it's the vertex and the second one it's the cost of
             // traveling to that vertex.

   std::vector<int> aDis(
      aG.getVerticesNum(),
      aINF );   // This vector contains the best distances
                // from the source to every path

   // We add the first element to the priority queue and also iniciate the
   // first distance.
   aPq.push( std::make_pair( aSrc, 0 ) );
   aDis[ aSrc ] = 0;

   int aX;      // This is used as an auxiliar value for the top of the PQ
   int aAdjX;   // This is used as an auxiliar value for the neighbor
   int aAdjXWeight;   // The cost of traveling to the neighbor vertex

   double aSumDistance = 0;
   double aCountEdge = 0;

   std::cout << "Our path is: " << aSrc << " ";

   //&& aPq.top().first != aDst with this we can specify the destination
   while ( !aPq.empty() )
   {
      aX = aPq.top().first;
      aPq.pop();

      for ( auto aValue : aG.getNeighbors( aX ) )   // Iterate neigbors
      {
         aAdjX = aValue;
         aAdjXWeight = aG.getEdgeVal( aX, aAdjX );
         // Now, we comparate if the old distance plus the cost to the
         // neighbor it's lower to its father cost, if that's the case we add
         // the neighbor to the PQ
         if ( aDis[ aAdjX ] > aDis[ aX ] + aAdjXWeight )
         {
            aDis[ aAdjX ] = aDis[ aX ] + aAdjXWeight;
            aPq.push( std::make_pair( aAdjX, aDis[ aAdjX ] ) );
         }
      }

      std::cout << aPq.top().first << " ";   // Printing the path
   }
   for ( int i = 0; i < aDis.size(); i++ )
   {
      if ( aDis.at( i ) < aINF )
      {
         aSumDistance += aDis.at( i );
         aCountEdge++;
      }
   }

   std::cout << "\nThe Distance from source " << aSrc << " to " << aDst
             << " is " << aDis[ aDst ] << std::endl;

   std::cout << "The average of lenght from the source to each vertex is : "
             << aSumDistance / aCountEdge << std::endl;

   return 0;
}
