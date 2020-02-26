// Simple program for adding the components of a vector
// Author Galan Fernando

#include <iostream>
#include <vector>

const int N = 40;   // size vector

inline void sum( int& p, std::vector<int>& data )
{
   p = 0;

   for ( int i = 0; i < N; i++ )
      p += data.at( i );
}

int main( int argc, char** argv )
{
   int accum = 0;

   std::vector<int> data;

   for ( int i = 0; i < N; i++ )
      data.push_back( i );

   sum( accum, data );   // Iterate and sum the components

   std::cout << "sum is " << accum << std::endl;

   return 0;
}