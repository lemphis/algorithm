#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int term[], int len, int M);

/**
 * @see [휴게소 세우기](https://www.acmicpc.net/problem/1477)
 */
int main() {
    fastio;
    int N, M, L;
    cin >> N >> M >> L;
    int rest[N + 2];
    rest[0] = 0, rest[N + 1] = L;
    for (int i = 1; i <= N; ++i) {
        cin >> rest[i];
    }

    sort(rest, rest + N + 2);

    int term_len = N + 1;
    int term[term_len];
    for (int i = 0; i < term_len; ++i) {
        term[i] = rest[i + 1] - rest[i] - 1;
    }

    int lo = 0, hi = L;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, term, term_len, M))
            lo = mid;
        else
            hi = mid;
    }

    cout << hi << endl;

    return 0;
}

bool check(int target, int term[], int len, int M) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        count += term[i] / target;
    }

    return count > M;
}