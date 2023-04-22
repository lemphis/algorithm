#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void draw(int N, int depth);

int main() {
    fastio;
    int n;
    cin >> n;
    int nums[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums, nums + n);

    long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        long temp = nums[i] * (sum - nums[i]);
        sum -= nums[i];
        ans += temp;
    }

    cout << ans;

    return 0;
}