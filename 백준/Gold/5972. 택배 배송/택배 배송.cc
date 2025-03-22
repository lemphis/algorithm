#include <climits>
#include <functional>
#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

vector<int> dijkstra(const vector<vector<pii>>& adj);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> adj(N);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A - 1].push_back({B - 1, C});
        adj[B - 1].push_back({A - 1, C});
    }

    cout << dijkstra(adj)[N - 1];

    return 0;
}

vector<int> dijkstra(const vector<vector<pii>>& adj) {
    vector<int> dist(adj.size(), INT_MAX);
    dist[0] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int d = top.first;
        int node = top.second;
        if (d != dist[node]) {
            continue;
        }
        for (int i = 0; i < adj[node].size(); ++i) {
            if (dist[adj[node][i].first] > d + adj[node][i].second) {
                dist[adj[node][i].first] = d + adj[node][i].second;
                pq.push({dist[adj[node][i].first], adj[node][i].first});
            }
        }
    }

    return dist;
}