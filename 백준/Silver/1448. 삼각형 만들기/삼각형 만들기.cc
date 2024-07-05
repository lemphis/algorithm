#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    int len[N];
    for (int i = 0; i < N; ++i) {
        cin >> len[i];
    }

    sort(len, len + N, greater<int>());
    for (int i = 0; i < N - 2; ++i) {
        if (len[i] < len[i + 1] + len[i + 2]) {
            cout << len[i] + len[i + 1] + len[i + 2];
            return 0;
        }
    }

    cout << -1;

    return 0;
}
