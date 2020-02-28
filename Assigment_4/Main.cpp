/*
Author: Galán Fernando
File: Main.cpp

Here is where the game of Hex is "played", as for now the moments are
randomized, this was used for debbuging most cases, further implementations
may include a menu for selecting a mode for 2 real players o 1 versus a non
inteligent computer player.
*/
#include <cassert>
#include <random>

#include "Board.hpp"

int main( const int argc, char** argv )
{
   int aTurn = 0;
   int aX, aY;

   int aSizeBoard = 0;
   std::cout << "Please enter the size of the board" << std::endl;
   std::cin >> aSizeBoard;
   assert( aSizeBoard > 2 );
   Board aBoard( aSizeBoard );

   aBoard.printBoard( std::cout );
   srand( time( 0 ) );
   while ( true )
   {
      aTurn = !aTurn;
      if ( aTurn == 1 )
      {
         do
         {
            aX = rand() % aSizeBoard;
            aY = rand() % aSizeBoard;
         } while ( !aBoard.placePiece( aX, aY, Players::BLUE ) );

         std::cout << "Player Blue: " << aX << ", " << aY << std::endl;
         aBoard.printBoard( std::cout );
      }

      else
      {
         do
         {
            aX = rand() % aSizeBoard;
            aY = rand() % aSizeBoard;

         } while ( !aBoard.placePiece( aX, aY, Players::RED ) );

         std::cout << "Player Red: " << aX << ", " << aY << std::endl;
         aBoard.printBoard( std::cout );
      }

      if ( aBoard.playerWin( aX, aY ) )
      {
         std::cout << ( aTurn ? "Blue" : "Red" ) << " win" << std::endl;
         aBoard.printBoard( std::cout );
         break;
      }
   }
   return 0;
}