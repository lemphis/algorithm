#include <cstdio>

using namespace std;

/**
 * @see [점프](https://www.acmicpc.net/problem/1890)
 */
int main() {
    int N;
    scanf("%d", &N);
    int board[N][N];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &board[r][c]);
        }
    }
    int memo[N][N];
    memo[0][0] = 1;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            // TODO: dp code 작성
        }
    }
    return 0;
}