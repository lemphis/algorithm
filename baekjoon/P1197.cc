#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void _union(int x, int y, int parents[]);
int _find(int x, int parents[]);

typedef struct Edge {
    int node[2];
    int distance;
    Edge(int x, int y, int distance) {
        this->node[0] = x;
        this->node[1] = y;
        this->distance = distance;
    }
    bool operator<(Edge &edge) { 
        return this->distance < edge.distance; 
    }
} Edge;

/**
 * @see [최소 스패닝 트리](https://www.acmicpc.net/problem/1197)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int V, E;
    cin >> V >> E;
    int parents[V];
    for (int i = 1; i <= V; ++i) {
        parents[i] = i;
    }

    vector<Edge> graph;
    while (E--) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.push_back(Edge(A, B, C));
    }
    sort(graph.begin(), graph.end());

    int weight = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (_find(graph[i].node[0], parents) != _find(graph[i].node[1], parents)) {
            weight += graph[i].distance;
            _union(graph[i].node[0], graph[i].node[1], parents);
        }
    }

    cout << weight << endl;
    return 0;
}

void _union(int x, int y, int parents[]) { 
    x < y ? parents[_find(y, parents)] = _find(x, parents) : parents[_find(x, parents)] = _find(y, parents); 
}

int _find(int x, int parents[]) { 
    return parents[x] == x ? x : (parents[x] = _find(parents[x], parents)); 
}