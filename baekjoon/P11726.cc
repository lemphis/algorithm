#include <cstdio>

using namespace std;

int total_tile_size(int n, int memo[]);

/**
 * @see [2×n 타일링](https://www.acmicpc.net/problem/11726)
 */
int main() {
    int n;
    scanf("%d", &n);
    int memo[1001] = {0};
    printf("%d", total_tile_size(n, memo));
    return 0;
}

int total_tile_size(int n, int memo[]) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (!memo[n]) {
        memo[n] = (total_tile_size(n - 1, memo) + total_tile_size(n - 2, memo)) % 10007;
    }
    return memo[n];
}