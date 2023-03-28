#include <cmath>
#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

void bfs(int src_x, int src_y, int dest_x, int dest_y, int n, pii arr[], bool visited[]);

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int src_x, src_y;
        cin >> src_x >> src_y;
        pii arr[n + 1];
        bool visited[n + 1];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].first >> arr[i].second;
            visited[i] = 0;
        }
        int dest_x, dest_y;
        cin >> dest_x >> dest_y;
        arr[n] = {dest_x, dest_y};
        visited[n] = 0;
        bfs(src_x, src_y, dest_x, dest_y, n, arr, visited);
    }

    return 0;
}

void bfs(int src_x, int src_y, int dest_x, int dest_y, int n, pii arr[], bool visited[]) {
    queue<pii> q;
    q.push({src_x, src_y});
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.first == dest_x && now.second == dest_y) {
            cout << "happy" << endl;
            return;
        }
        for (int i = 0; i <= n; ++i) {
            if (!visited[i]) {
                if (abs(now.first - arr[i].first) + abs(now.second - arr[i].second) <= 1000) {
                    q.push(arr[i]);
                    visited[i] = 1;
                }
            }
        }
    }
    cout << "sad" << endl;
}