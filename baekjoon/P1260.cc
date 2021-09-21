#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

void bfs(int start, int N);
void dfs(int node, int N);

bool graph[1001][1001];
bool visited[1001];

/**
 * @see [DFS와 BFS](https://www.acmicpc.net/problem/1260)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M, V;
    cin >> N >> M >> V;
    while (M--) {
        int r, c;
        cin >> r >> c;
        graph[r][c] = graph[c][r] = 1;
    }
    memset(visited, 0, sizeof(visited));
    dfs(V, N);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    bfs(V, N);
}

void bfs(int start, int N) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for (int i = 1; i <= N; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int node, int N) {
    visited[node] = 1;
    cout << node << ' ';
    for (int i = 1; i <= N; ++i) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, N);
        }
    }
}