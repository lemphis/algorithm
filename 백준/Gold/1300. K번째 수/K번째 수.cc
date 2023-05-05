#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int N, int k);

/**
 * @see [K번째 수](https://www.acmicpc.net/problem/1300)
 */
int main() {
    fastio;
    int N, k;
    cin >> N >> k;

    int lo = 0, hi = k;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, N, k))
            lo = mid;
        else
            hi = mid;
    }

    cout << hi << endl;

    return 0;
}

bool check(int target, int N, int k) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int temp = min(N, target / i);
        if (!temp) break;
        count += temp;
    }

    return count < k;
}