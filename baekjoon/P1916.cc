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
 * @see [최소비용 구하기](https://www.acmicpc.net/problem/1916)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<pii> adj[N + 1];
    for (int i = 0; i < M; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        adj[start].push_back(make_pair(weight, end));
    }
    int src, dest;
    cin >> src >> dest;

    int min_dist[N + 1];
    fill(min_dist, min_dist + N + 1, INFINITY);

    dijkstra(src, min_dist, adj);

    cout << min_dist[dest] << endl;

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