#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

/**
 * @see [LCS](https://www.acmicpc.net/problem/9251)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string a, b;
    cin >> a >> b;

    int a_len = a.size();
    int b_len = b.size();
    int memo[a_len + 1][b_len + 1];
    memset(memo, 0, sizeof(memo));

    for (int r = 1; r <= a_len; ++r) {
        for (int c = 1; c <= b_len; ++c) {
            if (a[r - 1] == b[c - 1]) {
                memo[r][c] = memo[r - 1][c - 1] + 1;
            } else {
                memo[r][c] = max(memo[r - 1][c], memo[r][c - 1]);
            }
        }
    }

    cout << memo[a_len][b_len] << endl;

    return 0;
}