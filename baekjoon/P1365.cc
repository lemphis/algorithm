#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [꼬인 전깃줄](https://www.acmicpc.net/problem/1365)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int seq[n], ans[n];
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    ans[0] = seq[0];
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (seq[i - 1] < seq[i] && seq[i] > ans[idx]) {
            ans[++idx] = seq[i];
        } else {
            int insert_idx = lower_bound(ans, ans + idx + 1, seq[i]) - ans;
            ans[insert_idx] = seq[i];
        }
    }

    cout << n - (idx + 1) << endl;

    return 0;
}