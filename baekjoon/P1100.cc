#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [하얀 칸](https://www.acmicpc.net/problem/1100)
 */
int main() {
    fastio;
    char board[8][8];
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && board[i][j] == 'F') {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}