#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [가장 큰 증가 부분 수열](https://www.acmicpc.net/problem/11055)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int seq[N], memo[N];
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    int max_sum = 0;
    for (int i = 0; i < N; ++i) {
        memo[i] = seq[i];
        for (int idx = 0; idx < i; ++idx) {
            if (seq[idx] < seq[i]) {
                memo[i] = max(memo[i], memo[idx] + seq[i]);
            }
        }
        max_sum = max(max_sum, memo[i]);
    }

    cout << max_sum << endl;

    return 0;
}
