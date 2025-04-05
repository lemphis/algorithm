#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using vvp = vector<vector<pii>>;

int dijkstra(vvp& graph, int s, int t);

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vvp graph(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int s, t;
    cin >> s >> t;

    cout << dijkstra(graph, s, t);

    return 0;
}

int dijkstra(vvp& graph, int s, int t) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [now_weight, now_node] = pq.top();
        pq.pop();
        if (dist[now_node] < now_weight) {
            continue;
        }

        for (auto& [next_node, next_weight] : graph[now_node]) {
            int weight = now_weight + next_weight;
            if (dist[next_node] > weight) {
                dist[next_node] = weight;
                pq.push({weight, next_node});
            }
        }
    }

    return dist[t];
}