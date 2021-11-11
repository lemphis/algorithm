#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

void topology_sort(vector<int> adj[], int in_degree[], int times[], int N, int W);

/**
 * @see [ACM Craft](https://www.acmicpc.net/problem/1005)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int times[N];
        for (int i = 0; i < N; ++i) {
            cin >> times[i];
        }

        vector<int> adj[N];
        int in_degree[N];
        memset(in_degree, 0, sizeof(in_degree));
        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            adj[X - 1].push_back(Y - 1);
            ++in_degree[Y - 1];
        }

        int W;
        cin >> W;

        topology_sort(adj, in_degree, times, N, W);
    }

    return 0;
}

void topology_sort(vector<int> adj[], int in_degree[], int times[], int N, int W) {
    queue<int> q;
    int result[N];
    for (int i = 0; i < N; ++i) {
        result[i] = times[i];
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int size = adj[curr].size();
        for (int idx = 0; idx < size; ++idx) {
            int next = adj[curr][idx];
            if (result[next] < result[curr] + times[next]) {
                result[next] = result[curr] + times[next];
            }
            --in_degree[next];
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << result[W - 1] << endl;
}