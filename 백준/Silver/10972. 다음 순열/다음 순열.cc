#include <algorithm>
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

    next_permutation(nums, nums + N);
    bool is_last = true;
    for (int i = 0; i < N; ++i) {
        if (nums[i] != i + 1) {
            is_last = false;
            break;
        }
    }

    if (is_last) {
        cout << -1;
    } else {
        for (int i = 0; i < N; ++i) {
            cout << nums[i] << ' ';
        }
    }

    return 0;
}