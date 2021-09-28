#include <cstdio>

using namespace std;

typedef long long ll;

/**
 * @see [X와 K](https://www.acmicpc.net/problem/1322)
 */
int main() {
    int X, K;
    scanf("%d %d", &X, &K);
    bool bit[64] = {0};
    int idx = 0;
    while (X > 0) {
        bit[idx++] = X & 1;
        X >>= 1;
    }
    ll unit = 1;
    ll Y = 0;
    for (idx = 0; idx < 64 && K; idx++, unit *= 2) {
        if (!bit[idx]) {
            if (K & 1) {
                Y += unit;
            }
            K >>= 1;
        }
    }
    printf("%llu", Y);
    return 0;
}
