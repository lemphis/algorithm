#include <algorithm>
#include <iostream>

using namespace std;

int lis(int items[], int memo[], int N);

/**
 * @see [가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    int items[N], memo[N];
    for (int i = 0; i < N; ++i) {
        cin >> items[i];
    }

    cout << lis(items, memo, N) << endl;
    return 0;
}

int lis(int items[], int memo[], int N) {
    int max_count = 1;
    for (int i = 0; i < N; ++i) {
        memo[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (items[i] > items[j] && memo[j] == memo[i]) {
                memo[i] = memo[j] + 1;
                max_count = max(memo[i], max_count);
            }
        }
    }

    return max_count;
}