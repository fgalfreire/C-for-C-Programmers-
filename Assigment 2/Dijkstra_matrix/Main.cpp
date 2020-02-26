#include <iostream>

#include "Algorithm.hpp"

int main( int argc, char** argv )
{
   Graph aG1( 50, 0.2 );

   std::cout << "Graph created succesfull" << std::endl;

   aG1.printMatrix();

   Algorithm aLg1;

   aLg1.Dijkstra( aG1, 0, 2 );

   Graph aG2( 50, 0.4 );

   std::cout << "\n\n\n" << std::endl;

   std::cout << "Graph created succesfull" << std::endl;

   aG2.printMatrix();

   Algorithm aLg2;

   aLg2.Dijkstra( aG2, 0, 2 );

   return 0;
}