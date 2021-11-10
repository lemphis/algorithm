#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [수 고르기](https://www.acmicpc.net/problem/2230)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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

    cout << ans << endl;
    return 0;
}