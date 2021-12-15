#include <iostream>

using namespace std;

#define endl '\n'
#define DIVISOR 1'000'000'009
#define MAX 1'000'000

/**
 * @see [1, 2, 3 더하기 3](https://www.acmicpc.net/problem/15988)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    int memo[MAX];
    memo[0] = 1;
    memo[1] = 2;
    memo[2] = 4;
    for (int i = 3; i < MAX; ++i) {
        memo[i] = (((memo[i - 3] + memo[i - 2]) % DIVISOR) + memo[i - 1]) % DIVISOR;
    }

    while (T--) {
        int n;
        cin >> n;
        cout << memo[n - 1] << endl;
    }
}