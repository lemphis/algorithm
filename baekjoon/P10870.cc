#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [피보나치 수 5](https://www.acmicpc.net/problem/10870)
 */
int main() {
    fastio;
    int n;
    cin >> n;
    int memo[21];

    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= 20; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    cout << memo[n];

    return 0;
}