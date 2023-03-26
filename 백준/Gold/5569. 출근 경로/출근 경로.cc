#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int RIGHT = 0;
const int UP = 1;
const int ONE = 0;
const int MORE_TWO = 1;
const int DIVIDE = 100'000;
int pos[100][100][2][2];

int main() {
    fastio;
    int w, h;
    cin >> w >> h;

    for (int i = 0; i < w; ++i) {
        pos[i][0][RIGHT][ONE] = 1;
    }
    for (int j = 0; j < h; ++j) {
        pos[0][j][UP][ONE] = 1;
    }

    for (int i = 1; i < w; ++i) {
        for (int j = 1; j < h; ++j) {
            pos[i][j][RIGHT][ONE] = (pos[i - 1][j][RIGHT][ONE] + pos[i - 1][j][RIGHT][MORE_TWO]) % DIVIDE;
            pos[i][j][UP][ONE] = (pos[i][j - 1][UP][ONE] + pos[i][j - 1][UP][MORE_TWO]) % DIVIDE;
            pos[i][j][RIGHT][MORE_TWO] = pos[i - 1][j][UP][ONE];
            pos[i][j][UP][MORE_TWO] = pos[i][j - 1][RIGHT][ONE];
        }
    }

    int count = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            count += pos[w - 1][h - 1][i][j];
        }
    }

    cout << count % DIVIDE;

    return 0;
}