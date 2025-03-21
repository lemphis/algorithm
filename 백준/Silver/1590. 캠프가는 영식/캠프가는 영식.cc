#include <iostream>
#include <limits>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, T;
    cin >> N >> T;
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) {
        int S, I, C;
        cin >> S >> I >> C;
        for (int j = 0; j < C; ++j) {
            if (S + (j * I) >= T) {
                if (ans > S + (j * I) - T) {
                    ans = S + (j * I) - T;
                }
                break;
            }
        }
    }

    if (ans == numeric_limits<int>::max()) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}