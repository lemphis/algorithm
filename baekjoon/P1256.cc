#include <cstdio>

using namespace std;

#define MAX 201

/**
 * @see [사전](https://www.acmicpc.net/problem/1256)
 */
int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int memo[MAX][MAX] = {0};
    for (int n = 0; n < MAX; ++n) {
        for (int r = 0; r <= n; ++r) {
            if (r == 0 || r == n) {
                memo[n][r] = 1;
            } else {
                memo[n][r] = memo[n - 1][r - 1] + memo[n - 1][r];
                if (memo[n][r] > 1'000'000'000) {
                    memo[n][r] = 1'000'000'001;
                }
            }
        }
    }
    if (memo[N + M][N] < K) {
        puts("-1");
    } else {
        int total = N + M;
        for (int i = 0; i < total; ++i) {
            if (memo[N + M - 1][M] < K) {
                putchar('z');
                K -= memo[N + M - 1][M];
                M--;
            } else {
                putchar('a');
                N--;
            }
        }
    }
    return 0;
}