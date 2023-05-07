#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int pos[], int mid, int N, int C, int& ans);

int main() {
    fastio;
    int N, C;
    cin >> N >> C;
    int pos[N];
    for (int i = 0; i < N; ++i) {
        cin >> pos[i];
    }

    sort(pos, pos + N);

    int lo = 0, hi = pos[N - 1] - pos[0] + 1;
    int ans = 0;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(pos, mid, N, C, ans)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << ans;

    return 0;
}

bool check(int pos[], int mid, int N, int C, int& ans) {
    int temp = pos[0];
    int count = 1;
    for (int i = 1; i < N; ++i) {
        if (pos[i] - temp >= mid) {
            ++count;
            temp = pos[i];
        }
    }
    if (count >= C) {
        ans = max(ans, mid);
        return true;
    }
    return false;
}
