#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

void dijkstra(const vector<vector<pii>>& adj, int start, int end);

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s - 1].push_back({e - 1, w});
    }
    int s, e;
    cin >> s >> e;

    dijkstra(adj, s - 1, e - 1);

    return 0;
}

void dijkstra(const vector<vector<pii>>& adj, int start, int end) {
    vector<pii> dist(adj.size(), {INT_MAX, 0});
    dist[start] = {0, 0};

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [w, s] = pq.top();
        pq.pop();
        if (w != dist[s].first) {
            continue;
        }
        for (int i = 0; i < adj[s].size(); ++i) {
            int e = adj[s][i].first;
            int next_weight = w + adj[s][i].second;
            if (dist[e].first > next_weight) {
                dist[e].first = next_weight;
                dist[e].second = s;
                pq.push({next_weight, e});
            }
        }
    }

    vector<int> ans;
    int next_node = end;
    while (next_node != start) {
        ans.push_back(next_node);
        next_node = dist[next_node].second;
    }

    ostringstream output;

    output << dist[end].first << endl;
    output << ans.size() + 1 << endl;
    output << start + 1 << ' ';
    for (int i = ans.size() - 1; i >= 0; --i) {
        output << ans[i] + 1 << ' ';
    }

    cout << output.str();
}