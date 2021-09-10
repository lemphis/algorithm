#include <iostream>

#define MAX 2187

using std::cin;
using std::cout;
using std::ios;

void solve(int x, int y, int n);
bool is_same(int x, int y, int n);

int paper[MAX][MAX];
int answer[3] = {0};

/**
 * @see [종이의 개수](https://www.acmicpc.net/problem/1780)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }
    solve(0, 0, N);
    for (int i = 0; i < 3; ++i) {
        cout << answer[i] << ' ';
    }
}

void solve(int x, int y, int n) {
    if (is_same(x, y, n)) {
        answer[paper[x][y] + 1] += 1;
        return;
    }
    int m = n / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            solve(x + i * m, y + j * m, m);
        }
    }
}

bool is_same(int x, int y, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (paper[x][y] != paper[x + i][y + j]) {
                return false;
            }
        }
    }
    return true;
}