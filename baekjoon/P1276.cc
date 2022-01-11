#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

typedef struct {
    int y;
    int x[2];
} Pos;

/**
 * @see [PLATFORME](https://www.acmicpc.net/problem/1276)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    Pos pos[N];
    for (int i = 0; i < N; ++i) {
        cin >> pos[i].y >> pos[i].x[0] >> pos[i].x[1];
    }

    sort(pos, pos + N, [](Pos& a, Pos& b) -> bool { return a.y > b.y; });

    int total_len = 0;
    for (int i = 0; i < N; ++i) {
        int left, right;
        left = right = pos[i].y;
        for (int j = i + 1; j < N; ++j) {
            if (pos[j].x[0] <= pos[i].x[0] && pos[i].x[0] < pos[j].x[1]) {
                left = pos[i].y - pos[j].y;
                break;
            }
        }
        for (int j = i + 1; j < N; ++j) {
            if (pos[j].x[0] < pos[i].x[1] && pos[i].x[1] <= pos[j].x[1]) {
                right = pos[i].y - pos[j].y;
                break;
            }
        }
        total_len += left + right;
    }

    cout << total_len << endl;

    return 0;
}