#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
#define INFINITY 1e9

using pii = pair<int, int>;

void dijkstra(int start, int min_dist[], vector<pii> adj[]);

/**
 * @see [파티](https://www.acmicpc.net/problem/1238)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M, X;
    cin >> N >> M >> X;
    vector<pii> adj[N + 1];
    for (int i = 0; i < M; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        adj[start].push_back(make_pair(weight, end));
    }

    int min_dist[N + 1], go_min_dist[N + 1];
    for (int i = 1; i <= N; ++i) {
        fill(min_dist, min_dist + N + 1, INFINITY);
        dijkstra(i, min_dist, adj);
        go_min_dist[i] = min_dist[X];
    }

    int back_min_dist[N + 1];
    fill(back_min_dist, back_min_dist + N + 1, INFINITY);
    dijkstra(X, back_min_dist, adj);

    int max_time = 0;
    for (int i = 1; i <= N; ++i) {
        if (go_min_dist[i] + back_min_dist[i] < INFINITY) {
            max_time = max(go_min_dist[i] + back_min_dist[i], max_time);
        }
    }

    cout << max_time << endl;

    return 0;
}

void dijkstra(int start, int min_dist[], vector<pii> adj[]) {
    min_dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int now_weight = pq.top().first;
        int now_vertex = pq.top().second;
        pq.pop();
        if (min_dist[now_vertex] < now_weight) {
            continue;
        }
        for (int i = 0; i < adj[now_vertex].size(); ++i) {
            int next_weight = now_weight + adj[now_vertex][i].first;
            int next_vertex = adj[now_vertex][i].second;
            if (min_dist[next_vertex] > next_weight) {
                min_dist[next_vertex] = next_weight;
                pq.push(make_pair(next_weight, next_vertex));
            }
        }
    }
}