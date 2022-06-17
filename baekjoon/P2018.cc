#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [수들의 합 5](https://www.acmicpc.net/problem/2018)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    int left = 1, right = 1, sum = 0, answer = 0;
    while (right <= N + 1) {
        if (sum < N) {
            sum += right++;
        } else if (sum == N) {
            answer++;
            sum += right++;
        } else {
            sum -= left++;
        }
    }

    cout << answer << endl;

    return 0;
}