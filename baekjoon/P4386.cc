#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Pos {
    float x;
    float y;
    int idx;
    Pos() { x = 0.0, y = 0.0, idx = 0; }
    Pos(float x, float y, int idx) : x(x), y(y), idx(idx) {}
} Pos;

typedef struct Edge {
    Pos node[2];
    float distance;
    Edge(Pos a, Pos b, float distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator<(Edge& edge) { return this->distance < edge.distance; }
} Edge;

int _find(int parents[], int x_idx);
void _union(int parents[], int x_idx, int y_idx);

/**
 * @see [별자리 만들기](https://www.acmicpc.net/problem/4386)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    int parents[n];
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }

    vector<Pos> vertices;
    for (int i = 0; i < n; ++i) {
        float x, y;
        cin >> x >> y;
        vertices.push_back(Pos(x, y, i));
    }

    vector<Edge> graph;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float distance = sqrt(pow(abs(vertices[j].x - vertices[i].x), 2) + pow(abs(vertices[j].y - vertices[i].y), 2));
            graph.push_back(Edge(vertices[i], vertices[j], distance));
        }
    }

    sort(graph.begin(), graph.end());
    float weight = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (_find(parents, graph[i].node[0].idx) != _find(parents, graph[i].node[1].idx)) {
            weight += graph[i].distance;
            _union(parents, graph[i].node[0].idx, graph[i].node[1].idx);
        }
    }

    cout.precision(6);
    cout << weight << endl;

    return 0;
}

int _find(int parents[], int x_idx) {
    if (x_idx == parents[x_idx]) {
        return x_idx;
    }
    return parents[x_idx] = _find(parents, parents[x_idx]);
}

void _union(int parents[], int x_idx, int y_idx) {
    x_idx = _find(parents, x_idx);
    y_idx = _find(parents, y_idx);
    if (x_idx < y_idx) {
        parents[y_idx] = x_idx;
    } else {
        parents[x_idx] = y_idx;
    }
}