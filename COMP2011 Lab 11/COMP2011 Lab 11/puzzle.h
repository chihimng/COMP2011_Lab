#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

enum Direction { HORIZONTAL, VERTICAL, DIAGONAL };

struct Position
{
   int row;
   int col;
};

class WordPuzzle
{
public:
   WordPuzzle();
   WordPuzzle(int n);
   // dynamically create the puzzle array
   void print();
   // print the contents of the puzzle array
   bool add_word(const char* word, Position pos, Direction d);
   // add a word to the puzzle array
   void complete_puzzle();
   // complete the puzzle array by adding random letters
   ~WordPuzzle();
   // deallocate the dynamic puzzle array

private:
   char** board;  // the content of the word
   int size = 0;  // the size of the puzzle board

};



#endif /* PUZZLE_H_ */
