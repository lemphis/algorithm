#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll count(ll target, ll M, ll times[]);
bool check(ll target, ll M, ll N, ll times[]);

/**
 * @see [놀이 공원](https://www.acmicpc.net/problem/1561)
 */
int main() {
    fastio;
    ll N, M;
    cin >> N >> M;
    ll times[M];
    ll max_time = 0;
    for (int i = 0; i < M; ++i) {
        cin >> times[i];
        max_time = max(times[i], max_time);
    }

    if (N <= M) {
        cout << N << endl;
        return 0;
    }

    ll lo = 0, hi = N * M * 30;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid, M, N, times))
            lo = mid;
        else
            hi = mid;
    }

    pii rest[M];
    for (int i = 0; i < M; ++i) {
        rest[i] = {lo % times[i], i};
    }

    ll cnt = N - count(lo, M, times);

    sort(rest, rest + M);

    cout << rest[cnt - 1].second + 1 << endl;

    return 0;
}

ll count(ll target, ll M, ll times[]) {
    ll count = M;
    for (int i = 0; i < M; ++i) {
        count += ((target - 1) / times[i]);
    }

    return count;
}

bool check(ll target, ll M, ll N, ll times[]) {
    return N > count(target, M, times);
}