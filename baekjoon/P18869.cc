#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [멀티버스 Ⅱ](https://www.acmicpc.net/problem/18869)
 */
int main() {
    fastio;
    int M, N;
    cin >> M >> N;
    pair<int, int> universe[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int input;
            cin >> input;
            universe[i][j] = {input, j};
        }
    }

    return 0;
}