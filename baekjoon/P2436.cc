#include <iostream>

using namespace std;

int _gcd(int, int);

/**
 * @see [공약수](https://www.acmicpc.net/problem/2436)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int gcd, lcm;
    cin >> gcd >> lcm;

    int quotient = lcm / gcd;
    int x1, x2;
    for (int i = 1; i * i <= quotient; ++i) {
        if (quotient % i == 0 && _gcd(quotient / i, i) == 1) {
            x1 = i;
            x2 = quotient / i;
        }
    }

    cout << x1 * gcd << ' ' << x2 * gcd << endl;

    return 0;
}

int _gcd(int a, int b) {
    return b ? _gcd(b, a % b) : a;
}