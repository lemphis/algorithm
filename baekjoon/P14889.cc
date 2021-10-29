#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [스타트와 링크](https://www.acmicpc.net/problem/14889)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int ability[N][N];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> ability[r][c];
        }
    }

    int comb[N];
    for (int i = 0; i < N / 2; ++i) {
        comb[i] = 0;
    }
    for (int i = N / 2; i < N; ++i) {
        comb[i] = 1;
    }

    int min_diff = 0xffffffff >> 1;
    do {
        int start_team = 0, link_team = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (comb[i] && comb[j]) {
                    start_team += ability[i][j] + ability[j][i];
                }
                if (!comb[i] && !comb[j]) {
                    link_team += ability[i][j] + ability[j][i];
                }
            }
        }
        min_diff = min(min_diff, abs(start_team - link_team));
    } while (next_permutation(comb, comb + N));

    cout << min_diff << endl;

    return 0;
}