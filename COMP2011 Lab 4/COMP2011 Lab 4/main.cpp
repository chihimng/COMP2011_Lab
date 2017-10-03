//
//  main.cpp
//  COMP2011 Lab 4
//
//  Created by Chihim Ng on 4/10/2017.
//  Copyright © 2017 Chihim Ng. All rights reserved.
//

#include <iostream>
using namespace std;

//Task 1 Write a function print_maze to print the maze.

//Task 2 Write a function is_valid_move to check if the move is valid or not.

//Task 3 Write a function update_maze to update the position of the player in the maze.

int main() {
    const int HEIGHT = 9;
    const int WIDTH = 18;
    char maze[] = {'#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#',
        '#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#',
        ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', ' ',
        '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#',
        '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#', 'E', '#', '#', '#', '#', '#', '#',
    };

    int x = 1, y = 1;
    char move;
    update_maze(maze, HEIGHT, WIDTH, x, y);
    bool is_valid;
    do {
        print_maze(maze, HEIGHT, WIDTH);
        cout << "Your current position is at: (" << x << ", " << y << ")"
        << endl;
        do {
            cout << "Please enter your move: (up:w, down:s, left:a, right:d)  ";
            cin >> move;
            is_valid = is_valid_move(maze, HEIGHT, WIDTH, x, y, move);
            if (is_valid) {
                switch (move) {
                    case 'w':
                        y--;
                        break;
                    case 's':
                        y++;
                        break;
                    case 'a':
                        x--;
                        break;
                    case 'd':
                        x++;
                        break;
                    default:
                        break;
                }
                update_maze(maze, HEIGHT, WIDTH, x, y);
            } else {
                cout << "The move is invalid!" << endl;
            }
        } while (!is_valid);
    } while (!(x == 11 && y == 8));

    cout << "Amazing! You have completed the maze!" << endl;

    return 0;

}
