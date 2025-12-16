#include <iostream>
using namespace std;

const int N = 9;

#define YELLOW "\033[33m"
#define RESET "\033[0m"

bool fixedCell[N][N];

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
    if (grid[row][x] == num || grid [x][col]== num)
    return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    if (grid[i + startRow][j + startCol] == num)
    return false;

    return true;
}
bool solveSudoku(int grid[N][N]) {
    int row = -1, col =-1;
    bool empty = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                empty = true;
                break;
            }
        }
        if (empty) break;
    }
    

if (!empty)
return true;

for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
        grid[row][col] = num;

        if (solveSudoku(grid))
        return true;

        grid[row][col] = 0;
    }
}
return false;
}

void printGrid(int grid[N][N]) {
    cout << "\nHasil Sudoku: \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fixedCell[i][j]) {
                cout << YELLOW << grid[i][j] << RESET << " ";
            } else {
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N];

    cout << "Masukkan Sudoku (9 baris, tiap baris 9 angka, gunakan  0 untuk sel kosong): ";

    for (int i = 0; i < N; i++) {
        cout << "Baris " << i+1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];

            fixedCell[i][j] = (grid[i][j] != 0);
        }
    }

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "Tidak ada solusi!\n";
    }

    return 0;
}