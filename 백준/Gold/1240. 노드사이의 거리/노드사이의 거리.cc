#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using vii = vector<vector<pii>>;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vii tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        --s;
        --e;
        tree[s].push_back({e, w});
        tree[e].push_back({s, w});
    }

    ostringstream output;
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;

        queue<pii> q;
        q.push({from, 0});

        vector<bool> visited(N, false);
        visited[from] = true;
        while (!q.empty()) {
            auto [now_node, now_weight] = q.front();
            if (now_node == to) {
                output << now_weight << endl;
                break;
            }
            q.pop();
            for (int j = 0; j < tree[now_node].size(); ++j) {
                if (!visited[tree[now_node][j].first]) {
                    int next_weight = now_weight + tree[now_node][j].second;
                    q.push({tree[now_node][j].first, next_weight});
                    visited[tree[now_node][j].first] = true;
                }
            }
        }
    }

    cout << output.str();

    return 0;
}