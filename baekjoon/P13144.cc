#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [List of Unique Numbers](https://www.acmicpc.net/problem/13144)
 */
int main() {
    fastio;
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    map<int, int> map;
    int left = 0, right = 0;
    map[nums[left]] = 1;
    long long count = 0;
    while (left < N) {
        while (right < N - 1 && map[nums[right + 1]] < 1) {
            right++;
            map[nums[right]]++;
        }
        count += (right - left + 1);
        map[nums[left]]--;
        left++;
    }

    cout << count << endl;

    return 0;
}