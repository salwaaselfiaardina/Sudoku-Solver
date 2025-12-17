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
    char ulang;

    do {
    int grid[N][N];
    cout << "======================= SOLVER SUDOKU =======================\n\n";

    cout << "Cara penggunaan:\n";
    cout << "1. Masukkan 9 baris angka, tiap baris terdiri dari 9 angka. \n";
    cout << "2. Gunakan angka 0 untuk sel yang kosong.\n";
    cout << "3. Gunakan spasi untuk memisahkan angka.\n";
    cout << "Contoh input untuk satu baris: 5 3 0 0 7 0 0 0 0\n\n";
    cout << "==============================================================\n";
    cout << "Masukkan Sudoku: \n";

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

    cout << "\nApakah kamu ingin mencoba lagi? (y/n): ";
    cin >> ulang;
    cout << endl;
} while (ulang == 'y' || ulang == 'Y');

cout << "Terima kasih telah menggunakan Solver Sudoku!\n";
    return 0;
}