#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ull = unsigned long long;

bool check(ull, int, int, const int[]);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int time[N];
    for (int i = 0; i < N; ++i) {
        cin >> time[i];
    }

    ull lo = 0, hi = 1e18;
    while (lo + 1 < hi) {
        ull mid = (lo + hi) >> 1;
        if (check(mid, N, M, time)) hi = mid;
        else lo = mid;
    }

    cout << hi << endl;

    return 0;
}

bool check(ull mid, int N, int M, const int time[]) {
    ull sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += mid / time[i];
        if (sum >= M) return true;
    }
    return sum >= M;
}