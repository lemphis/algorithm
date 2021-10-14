#include <cstdio>

using namespace std;

#define MAX 64

bool video[MAX][MAX] = {0};

void make_quadtree(int r, int c, int n);
bool is_same(int r, int c, int n);

/**
 * @see [쿼드트리](https://www.acmicpc.net/problem/1992)
 */
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        char line[N + 1];
        scanf("%s", line);
        for (int j = 0; j < N; ++j) {
            video[i][j] = line[j] == '1' ? 1 : 0;
        }
    }
    make_quadtree(0, 0, N);
    return 0;
}

void make_quadtree(int r, int c, int n) {
    if (is_same(r, c, n)) {
        putchar(video[r][c] ? '1' : '0');
    } else {
        putchar('(');
        make_quadtree(r, c, n / 2);
        make_quadtree(r, c + n / 2, n / 2);
        make_quadtree(r + n / 2, c, n / 2);
        make_quadtree(r + n / 2, c + n / 2, n / 2);
        putchar(')');
    }
}

bool is_same(int r, int c, int n) {
    bool target = video[r][c];
    for (int i = r; i < r + n; ++i) {
        for (int j = c; j < c + n; ++j) {
            if (video[i][j] != target) {
                return false;
            }
        }
    }
    return true;
}