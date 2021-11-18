#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [연속합](https://www.acmicpc.net/problem/1912)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int seq[n], memo[n];
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    memset(memo, 0, sizeof(memo));
    memo[0] = seq[0];
    int max_num = memo[0];
    for (int i = 1; i < n; ++i) {
        memo[i] = max(memo[i - 1] + seq[i], seq[i]);
        max_num = max(max_num, memo[i]);
        if (memo[i] < 0) memo[i] = 0;
    }

    cout << max_num << endl;

    return 0;
}