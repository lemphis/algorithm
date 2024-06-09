#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int s;
    cin >> s;

    for (int i = 0; i < n && s > 0; ++i) {
        int max = -1;
        int max_idx = i;
        for (int j = i; j <= i + s && j < n; ++j) {
            if (max < nums[j]) {
                max = nums[j];
                max_idx = j;
            }
        }
        for (int j = max_idx; j > i; --j) {
            swap(nums[j - 1], nums[j]);
            --s;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << nums[i] << ' ';
    }

    return 0;
}