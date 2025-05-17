#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int A[1'000], B[1'000];
int SA[1'000'000], SB[1'000'000];

int main() {
    fastio;

    int T;
    cin >> T;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    int sa_len = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += A[j];
            SA[sa_len] = sum;
            ++sa_len;
        }
    }

    int sb_len = 0;
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = i; j < m; ++j) {
            sum += B[j];
            SB[sb_len] = sum;
            ++sb_len;
        }
    }

    sort(SA, SA + sa_len);
    sort(SB, SB + sb_len);

    int idx = 0;
    long ans = 0;
    while (idx < sa_len) {
        auto hi = upper_bound(SA, SA + sa_len, SA[idx]);
        long len = hi - SA - idx;

        int target = T - SA[idx];
        auto sb_lo = lower_bound(SB, SB + sb_len, target);
        auto sb_hi = upper_bound(SB, SB + sb_len, target);

        ans += len * (sb_hi - sb_lo);

        idx = hi - SA;
    }

    cout << ans;

    return 0;
}