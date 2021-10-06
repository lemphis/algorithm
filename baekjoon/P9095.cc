#include <cstdio>

using namespace std;

/**
 * @see [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)
 */
int main() {
    int T;
    scanf("%d", &T);
    int memo[11] = {0};
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for (int i = 4; i <= 11; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", memo[n]);
    }

    return 0;
}