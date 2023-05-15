#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 61;
int memo[MAX][MAX][MAX];

void minus_hp(int a, int b, int c, int count);

int main() {
    fastio;
    int N;
    cin >> N;
    int hp[3] = {0};
    for (int i = 0; i < N; ++i) {
        cin >> hp[i];
    }
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            for (int k = 0; k < MAX; ++k) {
                memo[i][j][k] = MAX;
            }
        }
    }

    minus_hp(hp[0], hp[1], hp[2], 0);

    cout << memo[0][0][0];

    return 0;
}

void minus_hp(int a, int b, int c, int count) {
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    if (a == 0 && b == 0 && c == 0) {
        memo[0][0][0] = min(memo[0][0][0], count);
        return;
    }
    if (memo[a][b][c] != MAX && memo[a][b][c] <= count) {
        return;
    }
    memo[a][b][c] = count;

    minus_hp(a - 9, b - 3, c - 1, count + 1);
    minus_hp(a - 9, c - 3, b - 1, count + 1);
    minus_hp(b - 9, a - 3, c - 1, count + 1);
    minus_hp(b - 9, c - 3, a - 1, count + 1);
    minus_hp(c - 9, a - 3, b - 1, count + 1);
    minus_hp(c - 9, b - 3, a - 1, count + 1);
}