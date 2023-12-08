#include <iostream>
#include <cstdlib>
#include <ctime>

const int rows = 10;
const int columns = 10;

char maze[rows][columns];

void initializeMaze() {
     for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < columns; ++j) {
             maze[i][j] = '*';
         }
     }
}

void printMaze() {
     for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < columns; ++j) {
             std::cout << maze[i][j] << ' ';
         }
         std::cout << std::endl;
     }
}

bool isValidMove(int x, int y) {
     return x >= 0 && x < rows && y >= 0 && y < columns && maze[x][y] == '*';
}

bool solveMaze(int x, int y) {
     if (x == rows - 1 && y == columns - 1) {
         maze[x][y] = 'E'; // Exit found
         return true;
     }

     if (isValidMove(x, y)) {
         maze[x][y] = ' ';
         if (solveMaze(x + 1, y) || solveMaze(x, y + 1) || solveMaze(x - 1, y) || solveMaze(x, y - 1)) {
             return true;
         }
         maze[x][y] = '*'; // Return if the path does not lead to an exit
     }

     return false;
}

int main() {
     srand(static_cast<unsigned int>(time(0)));

     initializeMaze();

     // Create a starting point and exit
     maze[0][0] = 'S';
     maze[rows - 1][columns - 1] = 'E';

     // Create barriers in the maze
     for (int i = 0; i < rows * columns / 4; ++i) {
         maze[rand() % rows][rand() % columns] = '#';
     }

     std::cout << "Maze before solving:\n";
     printMaze();

     if (solveMaze(0, 0)) {
         std::cout << "\nMaze after solving:\n";
         printMaze();
     } else {
         std::cout << "\nNo solution found.\n";
     }

     return 0;
}
