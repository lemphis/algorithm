#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 500'000;
int parent[MAX];

int _find(int x);
void _union(int x, int y);

/**
 * @see [사이클 게임](https://www.acmicpc.net/problem/20040)
 */
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) parent[i] = i;
    int count = 0;
    for (int i = 0; i < m; ++i) {
        int src, target;
        cin >> src >> target;
        if (count == 0 && _find(src) == _find(target)) {
            count = i + 1;
        }
        _union(src, target);
    }

    cout << count << endl;

    return 0;
}

int _find(int x) {
    return parent[x] == x ? x : (parent[x] = _find(parent[x]));
}

void _union(int x, int y) {
    x = _find(parent[x]);
    y = _find(parent[y]);
    x < y ? parent[x] = y : parent[y] = x;
}