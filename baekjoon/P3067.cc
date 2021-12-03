#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [Coins](https://www.acmicpc.net/problem/3067)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int coin[N];
        for (int i = 0; i < N; ++i) {
            cin >> coin[i];
        }
        int M;
        cin >> M;
        int memo[M + 1];
        memset(memo, 0, sizeof(memo));
        memo[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = coin[i]; j <= M; ++j) {
                memo[j] += memo[j - coin[i]];
            }
        }

        cout << memo[M] << endl;
    }

    return 0;
}