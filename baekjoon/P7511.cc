#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000'000;
int parent[MAX];

int _find(int x);
void _union(int x, int y);

/**
 * @see [소셜 네트워킹 어플리케이션](https://www.acmicpc.net/problem/7511)
 */
int main() {
    fastio;
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cout << "Scenario " << i << ':' << endl;
        int n, k, m;
        cin >> n >> k;
        for (int j = 0; j < n; ++j) parent[j] = j;
        while (k--) {
            int a, b;
            cin >> a >> b;
            _union(a, b);
        }
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            cout << (_find(u) == _find(v) ? 1 : 0) << endl;
        }
        cout << endl;
    }

    return 0;
}

int _find(int x) {
    return x == parent[x] ? x : (parent[x] = _find(parent[x]));
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    x < y ? parent[y] = x : parent[x] = y;
}