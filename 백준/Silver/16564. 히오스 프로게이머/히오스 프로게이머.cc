#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;

ll check(ll, ll, const vector<ll> &);

int main() {
    fastio;
    ll N, K;
    cin >> N >> K;
    vector<ll> nums(N);
    ll min = 0xffffffff >> 1;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        if (min > nums[i]) {
            min = nums[i];
        }
    }

    ll lo = min, hi = min + K + 1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid, K, nums)) lo = mid;
        else hi = mid;
    }

    cout << lo << endl;

    return 0;
}

ll check(ll mid, ll K, const vector<ll> &nums) {
    for (long long num: nums) {
        ll diff = mid - num;
        if (diff > 0) {
            K -= diff;
        }
    }
    return K >= 0;
}