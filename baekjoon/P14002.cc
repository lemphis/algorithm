#include <iostream>
#include <utility>

using namespace std;

pair<int, int> lis(int items[], int memo[], int change[], int N);

/**
 * @see [가장 긴 증가하는 부분 수열 4](https://www.acmicpc.net/problem/14002)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    int items[N], memo[N], change[N];
    for (int i = 0; i < N; ++i) {
        cin >> items[i];
    }

    auto [max_len, max_idx] = lis(items, memo, change, N);
    int max_seq[max_len];
    for (int i = max_len - 1; i >= 0; --i) {
        max_seq[i] = items[max_idx];
        max_idx = change[max_idx];
    }

    cout << max_len << endl;
    for (int i = 0; i < max_len; ++i) {
        cout << max_seq[i] << ' ';
    }

    return 0;
}

pair<int, int> lis(int items[], int memo[], int change[], int N) {
    int max_len = 1;
    int max_idx = 0;
    for (int i = 0; i < N; ++i) {
        memo[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (items[i] > items[j] && memo[i] == memo[j]) {
                memo[i] = memo[j] + 1;
                change[i] = j;
            }
            if (memo[i] > max_len) {
                max_idx = i;
                max_len = memo[i];
            }
        }
    }

    return make_pair(max_len, max_idx);
}