#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [수들의 합 2](https://www.acmicpc.net/problem/2003)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int start, end, sum, count;
    start = end = sum = count = 0;
    while (start < N) {
        while (sum < M && end < N) {
            sum += nums[end++];
        }
        if (sum == M) {
            count++;
        }
        sum -= nums[start++];
    }

    cout << count << endl;
    return 0;
}