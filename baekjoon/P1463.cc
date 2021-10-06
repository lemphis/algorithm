#include <algorithm>
#include <cstdio>

using namespace std;

int min_count(int n, int memo[]);

/**
 * @see [1로 만들기](https://www.acmicpc.net/problem/1463)
 */
int main() {
    int n;
    scanf("%d", &n);
    int memo[1000001];
    printf("%d", min_count(n, memo));
    return 0;
}

int min_count(int n, int memo[]) {
    if (n == 1) return 0;
    for (int i = 2; i <= n; ++i) {
        memo[i] = memo[i - 1] + 1;
        if (i % 3 == 0) {
            memo[i] = min(memo[i / 3] + 1, memo[i]);
        }
        if (i % 2 == 0) {
            memo[i] = min(memo[i / 2] + 1, memo[i]);
        }
    }

    return memo[n];
}