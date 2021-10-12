#include <cstdio>

using namespace std;

void print_star(int r, int c, int n);

/**
 * @see [별 찍기 - 10](https://www.acmicpc.net/problem/2447)
 */
int main() {
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            print_star(r, c, N);
        }
        puts("");
    }
    return 0;
}

void print_star(int r, int c, int n) {
    if ((r / n) % 3 == 1 && (c / n) % 3 == 1) {
        putchar(' ');
    } else {
        if (n == 1) {
            putchar('*');
        } else {
            print_star(r, c, n / 3);
        }
    }
}