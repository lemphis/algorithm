#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
#define INFINITY 1e9
#define MAX 20'001

using pii = pair<int, int>;

vector<pii> adj[MAX];
int min_dist[MAX];

void dijkstra(int start);

/**
 * @see [최단경로](https://www.acmicpc.net/problem/1753)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int V, E, K;
    cin >> V >> E >> K;

    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
    }

    fill(min_dist, min_dist + V + 1, INFINITY);

    dijkstra(K);

    for (int i = 1; i <= V; ++i) {
        if (min_dist[i] >= INFINITY) {
            cout << "INF" << endl;
        } else {
            cout << min_dist[i] << endl;
        }
    }

    return 0;
}

void dijkstra(int start) {
    min_dist[start] = 0;
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (min_dist[current] < dist) continue;
        for (int i = 0; i < adj[current].size(); ++i) {
            int next_dist = dist + adj[current][i].first;
            int next = adj[current][i].second;
            if (next_dist < min_dist[next]) {
                min_dist[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}