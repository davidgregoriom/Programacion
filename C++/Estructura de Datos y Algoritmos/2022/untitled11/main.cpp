#include <iostream>
#include <vector>
#define UNASSIGNED 0
#define N 9
using namespace std;

bool FindUnassignedLocation(const vector <vector <int>> & grid , int& row, int& col);
bool isSafe(const vector <vector <int>> & grid, int row, int col, int num);

bool SolveSudoku(vector <vector  <int>>& grid) {
    int row, col;
    if (!FindUnassignedLocation(grid, row, col)) {
        return true; // success!
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (SolveSudoku(grid)) {
                return true;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool FindUnassignedLocation(const vector <vector <int>>& grid, int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool UsedInRow(const vector <vector <int>>& grid, int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool UsedInCol(const vector <vector <int>>& grid, int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool UsedInBox(const vector <vector <int>>& grid, int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(const vector <vector <int>>& grid, int row, int col, int num) {
    return !UsedInRow(grid, row, num) &&
        !UsedInCol(grid, col, num) &&
        !UsedInBox(grid, row - row % 3, col - col % 3, num);
}

void printGrid(const vector <vector <int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    vector <vector <int>> grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    if (SolveSudoku(grid)) {
        printGrid(grid);
    }
    else {
        printf("No solution exists");
    }
    return 0;
}
