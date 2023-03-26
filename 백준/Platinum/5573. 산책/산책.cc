#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000;
int map[MAX][MAX];
int memo[MAX][MAX];

int main() {
    fastio;
    int H, W, N;
    cin >> H >> W >> N;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> map[i][j];
        }
    }

    memo[0][0] = N - 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            memo[i + 1][j] += memo[i][j] / 2;
            memo[i][j + 1] += memo[i][j] / 2;
            if (memo[i][j] & 1) {
                if (map[i][j] & 1) {
                    ++memo[i][j + 1];
                } else {
                    ++memo[i + 1][j];
                }
            }
            map[i][j] = (map[i][j] + memo[i][j]) & 1;
        }
    }

    int row = 0, col = 0;
    while (1) {
        if (row == H || col == W) {
            break;
        }
        if (map[row][col] & 1) {
            ++col;
        } else {
            ++row;
        }
    }

    cout << row + 1 << ' ' << col + 1;

    return 0;
}