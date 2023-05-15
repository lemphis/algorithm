#include <algorithm>
#include <climits>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    int min_abs = INT_MAX;
    int lo = 0;
    int hi = N - 1;
    int left_num = nums[0];
    int right_num = nums[N - 1];
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        if (min_abs > abs(sum)) {
            min_abs = abs(sum);
            left_num = nums[lo];
            right_num = nums[hi];
        }
        if (sum <= 0) {
            ++lo;
        } else {
            --hi;
        }
    }

    cout << left_num << ' ' << right_num;

    return 0;
}