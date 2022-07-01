#include <iostream>
#include <unordered_set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 100'001;
int parent[MAX];

int _find(int x);
void _union(int x, int y);

/**
 * @see [여러분의 다리가 되어 드리겠습니다!](https://www.acmicpc.net/problem/20955)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) parent[i] = i;
    unordered_set<int> set;
    int count = 0;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (_find(u) == _find(v))
            count++;
        else
            _union(u, v);
    }
    for (int i = 1; i <= N; ++i) set.insert(_find(i));
    int not_union_node = set.size() - 1;

    cout << count + not_union_node << endl;

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