#include "Prim.hpp"

int main( int argc, char** argv )
{
   std::ifstream aFile( "data2.txt" );
   Graph aGraph( aFile );
   aGraph.printMatrix();
   Prim aPrim( aGraph, 0 );
   return 0;
}