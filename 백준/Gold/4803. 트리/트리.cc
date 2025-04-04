#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using vvi = vector<vector<int>>;

bool is_cycle(const vvi& adj, int node, vector<bool>& visited);

int main() {
    fastio;

    ostringstream output;
    for (int k = 1;; ++k) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        vvi adj(n);
        while (m--) {
            int s, e;
            cin >> s >> e;
            --s, --e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }

        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && !is_cycle(adj, i, visited)) {
                ++count;
            }
        }

        output << "Case " << k << ": ";
        if (count == 0) {
            output << "No trees.";
        } else if (count == 1) {
            output << "There is one tree.";
        } else {
            output << "A forest of " << count << " trees.";
        }
        output << endl;
    }

    cout << output.str();

    return 0;
}

bool is_cycle(const vvi& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    queue<pii> q;
    q.push({node, -1});
    while (!q.empty()) {
        auto [now, parent] = q.front();
        q.pop();
        for (int next : adj[now]) {
            if (!visited[next]) {
                q.push({next, now});
                visited[next] = true;
            } else if (next != parent) {
                return true;
            }
        }
    }

    return false;
}