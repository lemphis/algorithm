#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 1000

bool map[MAX][MAX] = {0};

/**
 * @see [벽 부수고 이동하기](https://www.acmicpc.net/problem/2206)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        char row[M + 1];
        cin >> row;
        for (int c = 0; c < M; ++c) {
            map[r][c] = row[c] - 48;
        }
    }
    // TODO: BFS 작성
}