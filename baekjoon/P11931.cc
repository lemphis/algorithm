#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [수 정렬하기 4](https://www.acmicpc.net/problem/11931)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + N, greater<int>());

    for (int i = 0; i < N; ++i) {
        cout << nums[i] << endl;
    }

    return 0;
}