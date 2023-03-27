#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void dfs(int idx, vector<int> graph[], vector<bool>& visited, int& count);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<int> graph[N + 1];
    while (M--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, count);
            ++count;
        }
    }

    cout << count;

    return 0;
}

void dfs(int idx, vector<int> graph[], vector<bool>& visited, int& count) {
    for (int i = 0; i < graph[idx].size(); ++i) {
        if (!visited[graph[idx][i]]) {
            visited[graph[idx][i]] = true;
            dfs(graph[idx][i], graph, visited, count);
        }
    }
}