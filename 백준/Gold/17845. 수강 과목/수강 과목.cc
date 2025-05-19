#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int dp[10'001];

int main() {
    fastio;

    long N, K;
    cin >> N >> K;
    int I[1'000], T[1'000];
    for (int i = 0; i < K; ++i) {
        cin >> I[i] >> T[i];
    }

    for (int i = 0; i < K; ++i) {
        for (int j = N; j > 0; --j) {
            if (j >= T[i]) {
                dp[j] = max(dp[j], dp[j - T[i]] + I[i]);
            }
        }
    }

    cout << dp[N];

    return 0;
}