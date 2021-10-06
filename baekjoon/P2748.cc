#include <cstdio>

using namespace std;

typedef long long ll;

ll fibo(int n, ll memo[]);

/**
 * @see [피보나치 수 2](https://www.acmicpc.net/problem/2748)
 */
int main() {
    int n;
    scanf("%d", &n);
    ll memo[91] = {0};
    printf("%lld", fibo(n, memo));
    return 0;
}

ll fibo(int n, ll memo[]) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (!memo[n]) {
        memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
    }
    return memo[n];
}