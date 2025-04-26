#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> dp(N, 1);
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    vector<int> dp_rev(N, 1);
    for (int i = N - 2; i >= 0; --i) {
        for (int j = N - 1; j > i; --j) {
            if (A[i] > A[j]) {
                dp_rev[i] = max(dp_rev[i], dp_rev[j] + 1);
            }
        }
    }

    int max_count = 0;
    for (int i = 0; i < N; ++i) {
        max_count = max(max_count, dp[i] + dp_rev[i] - 1);
    }

    cout << max_count;

    return 0;
}