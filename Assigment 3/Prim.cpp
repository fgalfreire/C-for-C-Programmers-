#include "Prim.hpp"

Prim::Prim( Graph& aGraph, const int aSrc )
{
   std::priority_queue<aPair, std::vector<aPair>, std::greater<aPair>> aPq;

   std::vector<int> aKey( aGraph.getVerticesNum(), INF );
   std::vector<int> aParent( aGraph.getVerticesNum(), -1 );
   std::vector<bool> aInMST( aGraph.getVerticesNum(), false );

   int aX;
   int aAdjX;
   int aAdjXWeight;

   int aSum;

   aPq.push( std::make_pair( 0, aSrc ) );
   aKey.at( aSrc ) = 0;

   while ( !aPq.empty() )
   {
      aX = aPq.top().second;
      aPq.pop();

      aInMST.at( aX ) = true;

      for ( auto aI : aGraph.getNeighbors( aX ) )
      {
         aAdjX = aI;
         aAdjXWeight = aGraph.getEdgeVal( aX, aAdjX );

         if ( aInMST.at( aAdjX ) == false && aKey.at( aAdjX ) > aAdjXWeight )
         {
            aKey.at( aAdjX ) = aAdjXWeight;
            aPq.push( std::make_pair( aKey.at( aAdjX ), aAdjX ) );
            aParent.at( aAdjX ) = aX;
         }
      }
   }
   std::cout << "Out Path is: "
             << "\n\t";
   for ( auto aI = 0; aI < (double)aParent.size(); aI++ )
   {
      std::cout << "(" << aParent.at( aI ) << "," << aI << ")"
                << "->";
      aSum = std::accumulate( aKey.begin(), aKey.end(), 0 );
   }

   std::cout << "\n The cost is: " << aSum << std::endl;
}
