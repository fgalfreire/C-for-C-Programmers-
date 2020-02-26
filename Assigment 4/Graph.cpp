/*
Author: Galán Fernando
File: Graph.cpp

Here I implemented both posible constructor for Graph, first versions which
take only the number of vertex for the graph and the other one which also
admits the density as a parameter. I did also implemented here a couple of
methods for the usage of the graph which are pretty self-explanatory and also
useful

*/

#include "Graph.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Graph::Graph( int aNumVert ) : aNumVert( aNumVert )
{
   if ( aNumVert <= 0 )
   {
      this->aNumVert = 0;
      return;
   }
   else
      aAdjMtr = std::vector<std::vector<int>>(
         aNumVert, std::vector<int>( aNumVert ) );
}

Graph::Graph( int aNumVert, double aDensity ) : aNumVert( aNumVert )
{
   if ( aNumVert <= 0 )
   {
      this->aNumVert = 0;
      return;
   }
   else
   {
      srand( time( 0 ) );

      double aProb;
      double aVal;

      aAdjMtr = std::vector<std::vector<int>>(
         aNumVert, std::vector<int>( aNumVert ) );

      for ( int i = 0; i < aNumVert; i++ )
      {
         for ( int j = 0; j < aNumVert; j++ )
         {
            aProb = rand() % 100 / 100.0;

            if ( i == j )
               addEdge( i, j, 0 );
            else if ( aProb < aDensity )
            {
               aVal = rand() % 10 + 1;
               addEdge( i, j, aVal );
            }
         }
      }
   }
}

Graph::Graph( std::istream& aFile )
{
   int aI, aJ, aVal;
   aFile >> aNumVert;
   if ( aNumVert <= 0 )
      return;

   aAdjMtr =
      std::vector<std::vector<int>>( aNumVert, std::vector<int>( aNumVert ) );

   while ( aFile >> aI >> aJ >> aVal )
      addEdge( aI, aJ, aVal );
}

bool Graph::isAdyacent( int aX, int aY )
{
   return aAdjMtr[ aX ][ aY ] > 0;
}

bool Graph::addEdge( int aX, int aY, int aVal )
{
   if ( aAdjMtr[ aX ][ aY ] > 0 )
      return false;

   aAdjMtr[ aX ][ aY ] = aVal;
   aAdjMtr[ aY ][ aX ] = aVal;

   return true;
}

bool Graph::delEdge( int aX, int aY )
{
   if ( aAdjMtr[ aX ][ aY ] > 0 )
   {
      aAdjMtr[ aX ][ aY ] = 0;
      aAdjMtr[ aX ][ aY ] = 0;
      return true;
   }

   return false;
}

bool Graph::setEdgeVal( int aX, int aY, int aVal )
{
   if ( aAdjMtr[ aX ][ aY ] > 0 )
   {
      aAdjMtr[ aX ][ aY ] = aVal;
      aAdjMtr[ aY ][ aX ] = aVal;
      return true;
   }

   return false;
}

void Graph::printMatrix()
{
   for ( int i = 0; i < getVerticesNum(); i++ )
   {
      for ( int j = 0; j < getVerticesNum(); j++ )
      {
         std::cout << aAdjMtr.at( i ).at( j ) << " ";
      }
      std::cout << std::endl;
   }
}

std::vector<int> Graph::getVertices()
{
   std::vector<int> aVert;

   for ( int i = 0; i < aNumVert; i++ )
      aVert.push_back( i );

   return aVert;
}

int Graph::getEdgeVal( int aX, int aY )
{
   return aAdjMtr[ aX ][ aY ];
}

std::vector<int> Graph::getNeighbors( int& aX )
{
   std::vector<int> aNeighbors;

   for ( int i = 0; i < aNumVert; i++ )
   {
      if ( aAdjMtr[ aX ][ i ] > 0 )
      {
         aNeighbors.push_back( i );
      }
   }

   return aNeighbors;
}