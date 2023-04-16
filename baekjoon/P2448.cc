#include <cstdio>
#include <cstdlib>

using namespace std;

bool board[3072][6144] = {0};
char base[3][6] = {
    "  *  ",
    " * * ",
    "*****",
};

void draw_board(int r, int c, int n);
void print_board(int n);

/**
 * @see [별 찍기 - 11](https://www.acmicpc.net/problem/2448)
 */
int main() {
    int N;
    scanf("%d", &N);
    draw_board(0, 0, N);
    print_board(N);
    return 0;
}

void draw_board(int r, int c, int n) {
    if (n == 3) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (base[i][j] == '*') {
                    board[i + r][j + c] = 1;
                }
            }
        }
    } else {
        draw_board(r, c + n / 2, n / 2);
        draw_board(r + n / 2, c, n / 2);
        draw_board(r + n / 2, c + n, n / 2);
    }
}

void print_board(int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < (n * 2 - 1); ++c) {
            putchar(board[r][c] ? '*' : ' ');
        }
        puts("");
    }
}