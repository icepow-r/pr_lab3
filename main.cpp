#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 6;
const int WIDTH = 3;

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;


void set_element(int matrix[][N], int x, int y, int offset_x, int offset_y) {
    *(*(matrix + y) + x) = (rand() % (N * N)) + 1;
    destCoord.X = (x + offset_x) * WIDTH;
    destCoord.Y = y + offset_y;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << *(*(matrix + y) + x);
    Sleep(10);
}

void print_matrix(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destCoord.X = (i + offset_x) * WIDTH;
            destCoord.Y = j + offset_y;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);
        }
    }
}

void quicksort(int arr[][N], int end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    int index = (f + l) / 2;
    mid = *(*(arr + index % N) + index / N);
    while (f < l) {
        while (*(*(arr + f % N) + f / N) < mid) f++;
        while (*(*(arr + l % N) + l / N) > mid) l--;
        if (f <= l) {
            swap(*(*(arr + f % N) + f / N), *(*(arr + l % N) + l / N));
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}


void show_a(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = offset_x + j * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j);

            destCoord.X = offset_x + (j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);

            destCoord.X = offset_x + j * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j + N / 2);

            destCoord.X = offset_x + (j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j + N / 2);
        }
    }
}

void show_b(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = (offset_x + (j + N / 2)) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j);

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j + N / 2);

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j + N / 2);
        }
    }
}

void show_c(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j);

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j + N / 2);

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j + N / 2);
        }
    }
}

void show_d(int matrix[][N], int offset_x, int offset_y) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j);

            destCoord.X = (offset_x + j + N / 2) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i + N / 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i + N / 2) + j + N / 2);

            destCoord.X = (offset_x + j) * WIDTH;
            destCoord.Y = offset_y + i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j + N / 2);
        }
    }
}

int main() {
    srand(time(nullptr));
    system("cls");

    int matrixA[N][N], matrixB[N][N], y = 0, x = 0;

    cout << "Исходные матрицы: ";
    for (int i = 0; i < N * 2 - 1; ++i) {
        switch (i % 4) {
            case 0:
                y = i / 4;
                for (x = i / 4; x < N - i / 4; ++x) {
                    set_element(matrixA, x, y, 0, 1);
                }
                break;
            case 1:
                x = N - i / 4 - 1;
                for (y = i / 4 + 1; y < N - i / 4; ++y) {
                    set_element(matrixA, x, y, 0, 1);
                }
                break;
            case 2:
                y = N - i / 4 - 1;
                for (x = N - i / 4 - 2; x >= i / 4; --x) {
                    set_element(matrixA, x, y, 0, 1);
                }
                break;
            case 3:
                x = i / 4;
                for (y = N - i / 4 - 2; y >= i / 4 + 1; --y) {
                    set_element(matrixA, x, y, 0, 1);
                }
                break;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; ++j) {
                set_element(matrixB, i, j, N + 2, 1);
            }
        } else {
            for (int j = N - 1; j >= 0; --j) {
                set_element(matrixB, i, j, N + 2, 1);
            }
        }
    }

    destCoord.X = 0;
    destCoord.Y = N + 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Перестановки первой матрицы: ";

    show_a(matrixA, 0, N + 3);
    show_b(matrixA, N + 1, N + 3);
    show_c(matrixA, (N + 1) * 2, N + 3);
    show_d(matrixA, (N + 1) * 3, N + 3);

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 2;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Перестановки второй матрицы: ";

    show_a(matrixB, 0, (N + 2) * 2 + 1);
    show_b(matrixB, N + 1, (N + 2) * 2 + 1);
    show_c(matrixB, (N + 1) * 2, (N + 2) * 2 + 1);
    show_d(matrixB, (N + 1) * 3, (N + 2) * 2 + 1);

    destCoord.X = 0;
    destCoord.Y = (N + 2) * 3;
    SetConsoleCursorPosition(hStdout, destCoord);

    cout << "Отсортированные матрицы: " << endl;
    quicksort(matrixA, N * N - 1, 0);
    quicksort(matrixB, N * N - 1, 0);
    print_matrix(matrixA, 0, (N + 2) * 3 + 1);
    print_matrix(matrixB, N + 1, (N + 2) * 3 + 1);
    return 0;
}
