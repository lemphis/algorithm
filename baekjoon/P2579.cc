#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [계단 오르기](https://www.acmicpc.net/problem/2579)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int stairs[n];
    int memo[n];
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < n; ++i) {
        cin >> stairs[i];
    }

    if (n == 1) {
        cout << stairs[0] << endl;
    } else if (n == 2) {
        cout << stairs[0] + stairs[1] << endl;
    } else if (n == 3) {
        cout << max(stairs[0] + stairs[1], stairs[0] + stairs[2]) << endl;
    } else {
        memo[0] = stairs[0];
        memo[1] = stairs[0] + stairs[1];
        memo[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

        for (int i = 3; i < n; ++i) {
            memo[i] = max(memo[i - 2], memo[i - 3] + stairs[i - 1]) + stairs[i];
        }

        cout << memo[n - 1] << endl;
    }

    return 0;
}