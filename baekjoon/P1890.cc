#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

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
    ll memo[N][N];
    memset(memo, 0, sizeof(memo));
    memo[0][0] = 1;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (r == N - 1 && c == N - 1) break;
            if (memo[r][c] > 0) {
                if (r + board[r][c] < N) memo[r + board[r][c]][c] += memo[r][c];
                if (c + board[r][c] < N) memo[r][c + board[r][c]] += memo[r][c];
            }
        }
    }
    printf("%lld\n", memo[N - 1][N - 1]);
    return 0;
}