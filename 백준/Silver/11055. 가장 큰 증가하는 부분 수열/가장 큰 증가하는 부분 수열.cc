#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
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
