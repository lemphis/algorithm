#include <cstdio>

using namespace std;

int gcd(int a, int b);

/**
 * @see [LCM](https://www.acmicpc.net/problem/5347)
 */
int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int _gcd = gcd(a, b);
        printf("%d\n", (a / _gcd * b / _gcd) * _gcd);
    }

    return 0;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }