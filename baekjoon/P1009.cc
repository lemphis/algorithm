#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [분산처리](https://www.acmicpc.net/problem/1009)
 */
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int base, exponent;
        cin >> base >> exponent;
        if (base > 10) base %= 10;
        exponent = exponent % 4 + 4;
        int result = (long)pow(base, exponent) % 10;
        if (result == 0) result = 10;
        cout << result << '\n';
    }
}