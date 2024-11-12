#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 6;
const int WIDTH = 5;

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;


void set_element(int matrix[][N], int x, int y, int offset_x, int offset_y) {
    *(*(matrix + y) + x) = (rand() % (N * N)) + 1;
    destCoord.X = (x + offset_x) * WIDTH;
    destCoord.Y = y + offset_y;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << *(*(matrix + y) + x);
    Sleep(50);
}

int main() {
    srand(time(nullptr));
    system("cls");

    int matrixA[N][N], matrixB[N][N], y = 0, x = 0;

    for (int i = 0; i < N * 2 - 1; ++i) {
        switch (i % 4) {
            case 0:
                y = i / 4;
                for (x = i / 4; x < N - i / 4; ++x) {
                    set_element(matrixA, x, y, 0, 0);
                }
                break;
            case 1:
                x = N - i / 4 - 1;
                for (y = i / 4 + 1; y < N - i / 4; ++y) {
                    set_element(matrixA, x, y, 0, 0);
                }
                break;
            case 2:
                y = N - i / 4 - 1;
                for (x = N - i / 4 - 2; x >= i / 4; --x) {
                    set_element(matrixA, x, y, 0, 0);
                }
                break;
            case 3:
                x = i / 4;
                for (y = N - i / 4 - 2; y >= i / 4 + 1; --y) {
                    set_element(matrixA, x, y, 0, 0);
                }
                break;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; ++j) {
                set_element(matrixB, i, j, N + 2, 0);
            }
        } else {
            for (int j = N - 1; j >= 0; --j) {
                set_element(matrixB, i, j, N + 2, 0);
            }
        }
    }

    destCoord.X = 0;
    destCoord.Y = 20;
    SetConsoleCursorPosition(hStdout, destCoord);
    return 0;
}
