#include <iostream>
#include <cstring>
#include "puzzle.h"
using namespace std;

/* Default constructor
 */
WordPuzzle::WordPuzzle()
{
   board = nullptr;
   size = 0;
}

// TODO 2: Implement the constructor to initialize a puzzle board of size n


/* Print the current state of the puzzle board
 */
void WordPuzzle::print()
{
   for (int i=0; i<size; i++)
   {
      for (int j=0; j<=i; j++)
      {
         cout << board[i][j];
         if (j!=i)
           cout << ",";
      }
      cout << endl;
   }
}

// TODO 3: Add a new word to the puzzle board at a specific position


/* Complete the empty positions of the puzzle board with random characters
 */
void WordPuzzle::complete_puzzle()
{
   for (int i=0; i<size; i++)
   {
      for (int j=0; j<=i; j++)
      {
         if (board[i][j] == '_')
            board[i][j] = 'a'+rand()%26;
      }
   }
}

// TODO 4:  Implement the destructor to deallocate the dyanmic puzzle



