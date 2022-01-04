#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int M, int N, int cookies[]);

/**
 * @see [과자 나눠주기](https://www.acmicpc.net/problem/16401)
 */
int main() {
    fastio;
    int M, N;
    cin >> M >> N;
    int cookies[N];
    for (int i = 0; i < N; ++i) {
        cin >> cookies[i];
    }

    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, M, N, cookies))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;

    return 0;
}

bool check(int target, int M, int N, int cookies[]) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (cookies[i] >= target) {
            count += cookies[i] / target;
        }
    }

    return count >= M;
}