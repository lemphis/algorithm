#include <cstdio>

using namespace std;

/**
 * @see [동전 0](https://www.acmicpc.net/problem/11047)
 */
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int coins[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &coins[i]);
    }
    int count = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (K >= coins[i]) {
            count += K / coins[i];
            K %= coins[i];
        }
    }
    printf("%d\n", count);
    return 0;
}