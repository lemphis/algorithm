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
 * @see [전력난](https://www.acmicpc.net/problem/6497)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    while (1) {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0) {
            break;
        }

        vector<Edge> graph;
        int max = 0;
        while (n--) {
            int x, y, z;
            cin >> x >> y >> z;
            graph.push_back(Edge(x, y, z));
            max += z;
        }

        int parents[m];
        for (int i = 0; i < m; ++i) {
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

        cout << max - weight << endl;
    }

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