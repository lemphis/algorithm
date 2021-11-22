#include <iostream>

using namespace std;

#define endl '\n'

int _lower_bound(int hi, int target, int ans[]);

/**
 * @see [가장 큰 증가 부분 수열 5](https://www.acmicpc.net/problem/14003)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int seq[N], ans[N], memo[N];
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    ans[0] = seq[0];
    memo[0] = 0;
    int idx = 1;
    for (int i = 1; i < N; ++i) {
        if (seq[i] > seq[i - 1] && ans[idx - 1] < seq[i]) {
            ans[idx] = seq[i];
            memo[i] = idx;
            ++idx;
        } else {
            int insert_idx = _lower_bound(idx, seq[i], ans);
            ans[insert_idx + 1] = seq[i];
            memo[i] = insert_idx + 1;
        }
    }

    cout << idx << endl;
    int temp[idx];
    int temp_idx = idx;
    for (int i = N - 1; i >= 0; --i) {
        if (memo[i] == idx - 1) {
            temp[idx - 1] = seq[i];
            --idx;
        }
    }

    for (int i = 0; i < temp_idx; ++i) {
        cout << temp[i] << ' ';
    }

    return 0;
}

int _lower_bound(int hi, int target, int ans[]) {
    int lo = -1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (ans[mid] >= target) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return lo;
}