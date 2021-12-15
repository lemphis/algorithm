#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [수 정렬하기 5](https://www.acmicpc.net/problem/15688)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    for (int i = 0; i < N; ++i) {
        cout << nums[i] << endl;
    }

    return 0;
}