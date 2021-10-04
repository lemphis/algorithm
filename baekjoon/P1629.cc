#include <cstdio>

using namespace std;

typedef long long ll;

ll pow(ll base, ll exponent, ll divisor);

/**
 * @see [곱셈](https://www.acmicpc.net/problem/1629)
 */
int main() {
    ll A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", pow(A, B, C) % C);
    return 0;
}

ll pow(ll base, ll exponent, ll divisor) {
    if (exponent == 1) {
        return base;
    } else {
        ll half = pow(base, exponent / 2, divisor) % divisor;
        if (exponent & 1) {
            return (half * half % divisor) * (base % divisor);
        }
        return half * half;
    }
}