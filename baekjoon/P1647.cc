#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

typedef struct Edge {
    int from;
    int to;
    int weight;
    bool operator<(Edge& a) { return this->weight < a.weight; }
} Edge;

int _find(int x, int parent[]);
void _union(int x, int y, int parent[]);

/**
 * @see [도시 분할 계획](https://www.acmicpc.net/problem/1647)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    Edge edges[M];
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edges[i] = {A - 1, B - 1, C};
    }

    sort(edges, edges + M);

    int parent[N];
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }

    vector<Edge> alive;
    int min_weight = 0;
    for (int i = 0; i < M; ++i) {
        if (_find(edges[i].from, parent) != _find(edges[i].to, parent)) {
            min_weight += edges[i].weight;
            alive.push_back(edges[i]);
            _union(edges[i].from, edges[i].to, parent);
        }
    }

    cout << min_weight - alive.back().weight << endl;

    return 0;
}

int _find(int x, int parent[]) { return parent[x] == x ? x : parent[x] = _find(parent[x], parent); }

void _union(int x, int y, int parent[]) { x < y ? parent[_find(y, parent)] = _find(x, parent) : parent[_find(x, parent)] = _find(y, parent); }