/*
Author: Galán Fernando
File: Board.cpp

This is the implementation of the board for the Hex game, the constructor only
admits a variable aSize which specificates the size of each side, the rest of
the methods are just auxiliars for the game.
*/
#include "Board.hpp"

#include <queue>

Board::Board( int aSize )
{
   this->theSize = aSize;
   aBoard = std::vector<std::vector<char>>(
      theSize, std::vector<char>( theSize, '*' ) );
   std::cout << "The board was created" << std::endl;

   aLine = "\\";

   for ( int i = 1; i < aSize; i++ )
      aLine += " / \\";
}
// In checkBorders I just check if a player is in both borders at the same
// time as the winner is the first to connect both ends
void Board::checkBorder(
   int aX,
   int aY,
   std::vector<bool>& aFlag,
   char aSide ) const
{
   if ( aSide == aBlue )
   {
      if ( aY == 0 )
         aFlag.at( 0 ) = true;

      if ( aY == theSize - 1 )
         aFlag.at( 1 ) = true;
   }

   else if ( aSide == aRed )
   {
      if ( aX == 0 )
         aFlag.at( 0 ) = true;
      if ( aX == theSize - 1 )
         aFlag.at( 1 ) = true;
   }
}

// placePiece just checks if a move is posible and then place the piece(Such
// an original name), illegal moves would be trying to put a red piece in a
// blue spot or out of range of the board.
bool Board::placePiece( int aX, int aY, Players aPlayers )
{
   if ( aBoard.at( aX ).at( aY ) != aBlank || inBoard( aX, aY ) == false )
      return false;

   if ( aPlayers == Players::BLUE )
      aBoard.at( aX ).at( aY ) = aBlue;
   if ( aPlayers == Players::RED )
      aBoard.at( aX ).at( aY ) = aRed;

   return true;
}

// This method is an implementation of a BFS, as after each move will seach
// throught the tree and call for the game end.
bool Board::playerWin( int aX, int aY ) const
{
   if ( inBoard( aX, aY ) == false || aBoard.at( aX ).at( aY ) == aBlank )
      return false;

   char aSide = aBoard.at( aX ).at( aY );

   std::vector<bool> aVecFlags( 2, false );
   std::vector<std::vector<bool>> aVisited(
      theSize, std::vector<bool>( theSize ) );
   std::queue<std::pair<int, int>> aTrace;

   aTrace.push( std::make_pair( aX, aY ) );
   aVisited.at( aX ).at( aY ) = true;

   while ( !aTrace.empty() )
   {
      auto aMove = aTrace.front();
      checkBorder( aMove.first, aMove.second, aVecFlags, aSide );
      aTrace.pop();

      for ( auto aI = 0; aI < 6; aI++ )
      {
         int aCurrX = aMove.first + aDirs[ aI ][ 0 ];
         int aCurrY = aMove.second + aDirs[ aI ][ 1 ];

         if (
            inBoard( aCurrX, aCurrY ) &&
            aBoard[ aCurrX ][ aCurrY ] == aSide &&
            aVisited[ aCurrX ][ aCurrY ] == false )
         {
            aVisited[ aCurrX ][ aCurrY ] = true;
            aTrace.push( std::make_pair( aCurrX, aCurrY ) );
         }
      }
   }
   return aVecFlags[ 0 ] && aVecFlags[ 1 ];
}

// Not used at the moment but could be an draft for the pie rule
// implementation, as another player could undo the other player move sub the
// aBlank for the player color.
bool Board::undoMove( int aX, int aY )
{
   aBoard.at( aX ).at( aY ) = aBlank;

   return true;
}

// This method format the print as the hex board look in real life
void Board::printBoard( std::ostream& aOut ) const
{
   if ( theSize <= 0 )
      return;

   aOut << aBoard[ 0 ][ 0 ];
   for ( int j = 1; j < theSize; j++ )
      aOut << " - " << aBoard[ 0 ][ j ];
   aOut << std::endl;

   std::string spaces = "";
   for ( int i = 1; i < theSize; i++ )
   {
      spaces += ' ';
      aOut << spaces << aLine << std::endl;
      spaces += ' ';
      aOut << spaces << aBoard[ i ][ 0 ];
      for ( int j = 1; j < theSize; j++ )
         aOut << " - " << aBoard[ i ][ j ];
      aOut << std::endl;
   }
}