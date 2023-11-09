#include <vector>
#include <iostream>
using namespace std;
const int N=4;

void printSolution(vector <vector <int>> board ) {
    static int k = 1;
    cout << k++ << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << "\n ";
    }
    cout << "\n";
}

bool isSafe(const vector <vector <int>> & board, int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

bool solveNQUtil(vector <vector <int>> & board, int col) {
    if (col == N) {
        printSolution(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void solveNQ() {
    auto board = vector <vector <int>>(N);
    for (int i = 0; i < N; ++i) {
        board[i].resize(N);
    }

    if (solveNQUtil(board, 0) == false) {
        cout << "\nSolution does not exist\n";
        return;
    }
    return;
}

int main() {
    solveNQ();
    return 0;
}
