#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<int>>;

void dfs(const vvi& graph, int start, int& idx, vector<int>& ans);

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
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    vector<int> ans(N + 1, 0);
    ans[R] = 1;
    int idx = 1;
    dfs(graph, R, idx, ans);

    ostringstream output;
    for (int i = 1; i <= N; ++i) {
        output << ans[i] << endl;
    }

    cout << output.str();

    return 0;
}

void dfs(const vvi& graph, int start, int& idx, vector<int>& ans) {
    for (int next : graph[start]) {
        if (ans[next] == 0) {
            ans[next] = ++idx;
            dfs(graph, next, idx, ans);
        }
    }
}