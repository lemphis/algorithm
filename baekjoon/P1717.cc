#include <cstdio>

using namespace std;

int parent[1000001];

int _find(int x);
void _union(int x, int y);

/**
 * @see [집합의 표현](https://www.acmicpc.net/problem/1717)
 */
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    while (m--) {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0) {
            _union(a, b);
        } else {
            puts(_find(a) == _find(b) ? "YES" : "NO");
        }
    }

    return 0;
}

int _find(int x) { return x == parent[x] ? x : (parent[x] = _find(parent[x])); }

void _union(int x, int y) { parent[_find(y)] = _find(x); }