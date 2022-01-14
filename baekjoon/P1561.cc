#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;

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
    for (int i = 0; i < M; ++i) {
        cin >> times[i];
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

    int cnt = count(hi, M, times) - count(lo, M, times);
    vector<int> rest;
    for (int i = 0; i < M; ++i) {
        if (lo % times[i] == 0) rest.push_back(i + 1);
    }

    cout << rest[diff - 1] << endl;

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