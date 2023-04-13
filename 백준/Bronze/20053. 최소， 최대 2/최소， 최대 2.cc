#include <iostream>
#include <algorithm>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int nums[N];
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }
        cout << *min_element(nums, nums + N) << ' ' << *max_element(nums, nums + N) << endl;
    }

    return 0;
}