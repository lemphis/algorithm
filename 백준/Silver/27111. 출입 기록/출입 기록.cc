#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    bool is_in[200'001];
    memset(is_in, 0, sizeof(is_in));

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        if ((is_in[a] && b == 1) || (!is_in[a] && b == 0)) {
            ans += 1;
        } else {
            is_in[a] = !is_in[a];
        }
    }

    for (int i = 1; i < 200'001; ++i) {
        if (is_in[i]) {
            ++ans;
        }
    }

    cout << ans;

    return 0;
}