#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pll = pair<long long, long long>;

const int MAX = 10'000;
pll pos[MAX];

/**
 * @see [다각형의 면적](https://www.acmicpc.net/problem/2166)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> pos[i].first >> pos[i].second;
    pos[N] = pos[0];

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (pos[i].first * pos[i + 1].second);
        ans -= (pos[i].second * pos[i + 1].first);
    }

    cout.setf(ios::fixed);
    cout.precision(1);
    cout << abs(ans) / 2.0 << endl;

    return 0;
}