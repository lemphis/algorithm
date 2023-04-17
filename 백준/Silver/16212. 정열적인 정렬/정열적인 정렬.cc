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

    sort(nums, nums + N);

    for (int i = 0; i < N; ++i) {
        cout << nums[i] << ' ';
    }

    return 0;
}