#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pll = pair<long, long>;

long dijkstra(const vector<vector<pll>>& adj);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<bool> is_show(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        is_show[i] = a & 1;
    }
    is_show[N - 1] = false;
    vector<vector<pll>> graph(N);
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        if (!is_show[a] && !is_show[b]) {
            graph[a].push_back({b, t});
            graph[b].push_back({a, t});
        }
    }

    long ans = dijkstra(graph);
    cout << (ans == LONG_MAX ? -1 : ans);

    return 0;
}

long dijkstra(const vector<vector<pll>>& adj) {
    vector<long> dist(adj.size(), LONG_MAX);
    dist[0] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [now_w, now] = pq.top();
        pq.pop();
        if (now_w > dist[now]) {
            continue;
        }

        for (auto [next, next_w] : adj[now]) {
            if (dist[next] > now_w + next_w) {
                dist[next] = now_w + next_w;
                pq.push({now_w + next_w, next});
            }
        }
    }

    return dist[adj.size() - 1];
}