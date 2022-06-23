#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000'000;
int nums[MAX];

/**
 * @see [가장 긴 짝수 연속한 부분 수열 (large)](https://www.acmicpc.net/problem/22862)
 */
int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> nums[i];

    int odd_count = 0, left = 0, right = 0, max_len = 0;
    while (right < N) {
        if (nums[right] & 1) {
            if (odd_count == K) {
                while (true) {
                    if (nums[left] & 1) {
                        left++;
                        break;
                    }
                    left++;
                }
            } else {
                odd_count++;
            }
        }

        if (max_len < right - left + 1) {
            max_len = right - left + 1;
        }
        right++;
    }

    cout << max_len - odd_count << endl;

    return 0;
}