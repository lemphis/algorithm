#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'
#define DIVISOR 1'000'000'000

/**
 * @see [자두나무](https://www.acmicpc.net/problem/2240)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T, W;
    cin >> T >> W;

    if (T <= W) {
        cout << T << endl;
        return 0;
    }

    int tree[T + 1];
    int memo[T + 1][W + 1];
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i <= T; ++i) {
        cin >> tree[i];
    }

    int max_count = 0;
    for (int i = 1; i <= T; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j == 0) {
                memo[i][j] = memo[i - 1][j] + (tree[i] == 1);
            } else {
                int add_value = tree[i] == ((j & 1) == 0 ? 1 : 2);
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - 1]) + add_value;
            }

            max_count = max(max_count, memo[i][j]);
        }
    }

    cout << max_count << endl;

    return 0;
}