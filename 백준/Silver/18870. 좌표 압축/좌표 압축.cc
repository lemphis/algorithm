#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

/**
 * @see [좌표 압축](https://www.acmicpc.net/problem/18870)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    pii pos[N];
    for (int i = 0; i < N; ++i) {
        cin >> pos[i].first;
        pos[i].second = i;
    }

    sort(pos, pos + N);
    int ans[N];
    int count = 0;
    ans[pos[0].second] = 0;
    for (int i = 1; i < N; ++i) {
        if (pos[i].first != pos[i - 1].first) {
            count++;
        }
        ans[pos[i].second] = count;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}