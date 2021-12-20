#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int check(int K, int pivot, int len[]);

/**
 * @see [랜선 자르기](https://www.acmicpc.net/problem/1654)
 */
int main() {
    fastio;
    int K, N;
    cin >> K >> N;
    int len[K];
    int max_len = 0;
    for (int i = 0; i < K; ++i) {
        cin >> len[i];
        max_len = max(max_len, len[i]);
    }

    long long lo = 0, hi = (long long)max_len + 1;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) >> 1;
        if (check(K, mid, len) < N)
            hi = mid;
        else
            lo = mid;
    }

    cout << lo << endl;

    return 0;
}

int check(int K, int pivot, int len[]) {
    int count = 0;
    for (int i = 0; i < K; ++i) {
        count += len[i] / pivot;
    }

    return count;
}