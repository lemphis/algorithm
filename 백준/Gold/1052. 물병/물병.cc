#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    int ans = 0;
    while (1) {
        int total = n;
        while (total) {
            if (total & 1) {
                ++cnt;
            }
            total >>= 1;
        }
        if (cnt <= k) {
            break;
        }
        cnt = 0;
        ++n;
        ++ans;
    }

    cout << ans;

    return 0;
}