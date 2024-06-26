#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    int sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += nums[i];
    }
    int ans = sum;
    for (int i = K; i < N; ++i) {
        sum = sum - nums[i - K] + nums[i];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}