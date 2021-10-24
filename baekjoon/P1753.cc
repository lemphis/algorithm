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

/**
 * @see [최단경로](https://www.acmicpc.net/problem/1753)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int V, E, K;
    cin >> V >> E >> K;
    vector<Edge> graph;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back(Edge(u, v, w));
    }
    // TODO: 최단 경로 구하는 코드 작성
    return 0;
}