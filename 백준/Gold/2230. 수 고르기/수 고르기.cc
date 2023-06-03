#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int seq[N];
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    sort(seq, seq + N);

    int ans = 0xffffffff >> 1;
    int i = 0, j = i + 1;
    while (j < N) {
        if (seq[j] - seq[i] >= M) {
            ans = min(ans, seq[j] - seq[i]);
            i++;
        } else {
            j++;
        }
    }

    cout << ans;
    
    return 0;
}