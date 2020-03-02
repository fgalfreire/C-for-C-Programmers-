/*
Author: Galán Fernando
File: Board.hpp

This file it's just the declaration of the Hex's board, also it's used for
declaring the Players
*/

#include <iostream>
#include <vector>

enum class Players
{
   BLUE,
   RED
};

class Board
{
private:
   const int aDirs[ 6 ][ 2 ] = {{-1, 0},
                                {-1, 1},   // top left, top right
                                {0, -1},
                                {0, 1},   // left, right
                                {1, -1},
                                {1, 0}};   // bottom left, bottom right

   const char aBlue = 'B';
   const char aRed = 'R';
   const char aBlank = '*';
   int theSize;
   std::string aLine;
   std::vector<std::vector<char>> aBoard;

public:
   Board( int aSize );

   bool placePiece( int aX, int aY, Players aPlayers );

   bool undoMove( int aX, int aY );

   bool playerWin( int aX, int aY ) const;

   bool inBoard( int aX, int aY ) const
   {
      return aX >= 0 && aX < theSize && aY >= 0 && aY < theSize;
   }

   void checkBorder( int aX, int aY, std::vector<bool>& aFlag, char aSide )
      const;

   void printBoard( std::ostream& out ) const;

   ~Board() = default;
};
