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
WordPuzzle::WordPuzzle(int n) {
    this->board = new char* [n];

    for (int i = 0; i < n; i++) {
        this->board[i] = new char[i+1];
        for (int j = 0; j < i; j++) {
            this->board[i][j] = '_';
        }
    }
    this->size = n;
}



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
bool WordPuzzle::add_word(const char* word, Position pos, Direction d) {

    switch (d) {
        case HORIZONTAL:
            // check length
            if (strlen(word) > (this->size - pos.row)) {
                return false;
            }
            // check if slot available
            for (int i = 0; i < strlen(word); i++) {
                if (this->board[pos.row][pos.col+i] == '_') {
                    continue;
                } else {
                    return false;
                }
            }
            // write to array
            for (int i = 0; i < strlen(word); i++) {
                this->board[pos.row][pos.col+i] = word[i];
            }
            return true;
        case VERTICAL:
            // check length
            if (strlen(word) > (this->size - pos.col)) {
                return false;
            }
            // check if slot available
            for (int i = 0; i < strlen(word); i++) {
                if (this->board[pos.row+i][pos.col] == '_') {
                    continue;
                } else {
                    return false;
                }
            }
            // write to array
            for (int i = 0; i < strlen(word); i++) {
                this->board[pos.row+i][pos.col] = word[i];
            }
            return true;
        case DIAGONAL:
            // check length
            if (strlen(word) > (this->size - pos.row)) {
                return false;
            }
            // check if slot available
            for (int i = 0; i < strlen(word); i++) {
                if (this->board[pos.row+i][pos.col+i] == '_') {
                    continue;
                } else {
                    return false;
                }
            }
            // write to array
            for (int i = 0; i < strlen(word); i++) {
                this->board[pos.row+i][pos.col+i] = word[i];
            }
            return true;
    }
}

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

WordPuzzle::~WordPuzzle() {
    for (int i = 0; i < this->size; i++) {
        delete[] this->board[i];
        this->board[i] = nullptr;
    }
    delete[] this->board;
    this->board = nullptr;
}

