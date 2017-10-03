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
void print_maze(char maze[], int height, int width) {
    for (int i = 0; i < height * width; i++) {
        if (!(i % width)) cout << '\n' ;
        cout << maze[i];
    }
    cout << '\n';
}

//Task 2 Write a function is_valid_move to check if the move is valid or not.

bool is_valid_move(char maze[], int height, int width, int x, int y, char move) {
    // Parse into 2D array
    char maze2d[100][100] = {};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze2d[i][j] = maze[width * i + j];
        }
    }

    switch (move) {
        case 'w':
            if ((y - 1) < 0) return false;
            return maze2d[y - 1][x] != '#';
        case 'a':
            if ((x - 1) < 0) return false;
            return maze2d[y][x - 1] != '#';
        case 's':
            if ((y + 1) >= height) return false;
            return maze2d[y + 1][x] != '#';
        case 'd':
            if ((x + 1) >= width) return false;
            return maze2d[y][x + 1] != '#';
        default:
            return false;
    }
}

//Task 3 Write a function update_maze to update the position of the player in the maze.
void update_maze(char maze[], int height, int width, int x, int y) {
    for (int i = 0; i < height * width; i++) {
        if (maze[i] == 'P') maze[i] = ' ';
    }
    maze[y * width + x] = 'P';
}

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
