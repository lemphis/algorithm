#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int NODE_MAX = 200;
const int PLAN_MAX = 1'000;
int parent[NODE_MAX];
int plan[PLAN_MAX];
bool map[NODE_MAX][NODE_MAX];

int _find(int x);
void _union(int x, int y);
bool every(int size);

/**
 * @see [여행 가자](https://www.acmicpc.net/problem/1976)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) parent[i] = i;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 1) _union(r, c);
        }
    }

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        plan[i] = num - 1;
    };

    cout << (every(M) ? "YES" : "NO") << endl;

    return 0;
}

int _find(int x) {
    return x == parent[x] ? x : (parent[x] = _find(parent[x]));
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if (x == y) return;
    x < y ? parent[y] = x : parent[x] = y;
}

bool every(int size) {
    int standard = parent[plan[0]];
    for (int i = 1; i < size; ++i) {
        if (parent[plan[i]] != standard) {
            return false;
        }
    }
    return true;
}