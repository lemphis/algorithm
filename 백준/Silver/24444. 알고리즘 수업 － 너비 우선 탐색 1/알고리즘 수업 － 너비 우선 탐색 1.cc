#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<int>>;

int main() {
    fastio;

    int N, M, R;
    cin >> N >> M >> R;
    vvi graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    ostringstream output;

    vector<int> visited(N + 1, 0);
    visited[R] = 1;
    queue<int> q;
    q.push(R);
    int idx = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); ++i) {
            if (!visited[graph[now][i]]) {
                q.push(graph[now][i]);
                visited[graph[now][i]] = ++idx;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        output << visited[i] << endl;
    }

    cout << output.str();

    return 0;
}