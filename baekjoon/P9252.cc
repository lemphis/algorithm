#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl '\n'

/**
 * @see [LCS 2](https://www.acmicpc.net/problem/9252)
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

    stack<char> ans;
    while (a_len > 0 && b_len > 0) {
        if (memo[a_len - 1][b_len] == memo[a_len][b_len]) {
            a_len--;
        } else if (memo[a_len][b_len - 1] == memo[a_len][b_len]) {
            b_len--;
        } else {
            ans.push(a[a_len - 1]);
            a_len--;
            b_len--;
        }
    }

    int ans_size = ans.size();
    while (ans_size--) {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}