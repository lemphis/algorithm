#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    long N, K;
    cin >> N >> K;
    vector<long> nums(N);
    for (long& num : nums) {
        cin >> num;
    }
    for (long i = 0; i < N; ++i) {
        K -= nums[i];
        if (K < 0) {
            cout << i + 1;
            return 0;
        }
    }
    for (long i = N - 1; i >= 0; --i) {
        K -= nums[i];
        if (K < 0) {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}