#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [오름세](https://www.acmicpc.net/problem/3745)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    while (cin >> n) {
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

        cout << idx + 1 << endl;
    }

    return 0;
}