#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'
#define DIVISOR 1'000'000'000

/**
 * @see [피보나치 수의 확장](https://www.acmicpc.net/problem/1788)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int memo[abs(n) + 2];
    if (n < 0) {
        memo[abs(n) + 1] = 1;
        memo[abs(n)] = 0;
        for (int i = abs(n) - 1; i >= 0; --i) {
            memo[i] = (memo[i + 2] - memo[i + 1]) % DIVISOR;
        }
        if (memo[0] < 0)
            cout << -1 << endl;
        else if (memo[0] > 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        cout << abs(memo[0]) << endl;
    } else {
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            memo[i] = (memo[i - 1] + memo[i - 2]) % DIVISOR;
        }
        if (memo[n] < 0)
            cout << -1 << endl;
        else if (memo[n] > 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        cout << memo[n] << endl;
    }

    return 0;
}