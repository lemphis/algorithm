#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Edge {
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator<(Edge& edge) { return this->distance < edge.distance; }
} Edge;

int _find(int parents[], int x);
void _union(int parents[], int x, int y);

/**
 * @see [네트워크 연결](https://www.acmicpc.net/problem/1922)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<Edge> graph;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back(Edge(a, b, c));
    }

    int parents[N + 1];
    for (int i = 1; i <= N; ++i) {
        parents[i] = i;
    }

    sort(graph.begin(), graph.end());
    int weight = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (_find(parents, graph[i].node[0]) != _find(parents, graph[i].node[1])) {
            weight += graph[i].distance;
            _union(parents, graph[i].node[0], graph[i].node[1]);
        }
    }

    cout << weight << endl;

    return 0;
}

int _find(int parents[], int x) {
    if (x == parents[x]) {
        return x;
    }
    return parents[x] = _find(parents, parents[x]);
}

void _union(int parents[], int x, int y) {
    x = _find(parents, x);
    y = _find(parents, y);
    if (x < y) {
        parents[y] = x;
    } else {
        parents[x] = y;
    }
}