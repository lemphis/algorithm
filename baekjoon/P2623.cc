#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

void topology_sort(vector<int> adj[], int in_degree[], int result[], int N);

/**
 * @see [음악프로그램](https://www.acmicpc.net/problem/2623)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<int> adj[N + 1];
    int in_degree[N + 1];
    memset(in_degree, 0, sizeof(in_degree));
    while (M--) {
        int count;
        cin >> count;
        int prev;
        for (int i = 0; i < count; ++i) {
            int next;
            cin >> next;
            if (i > 0) {
                adj[prev].push_back(next);
                ++in_degree[next];
            }
            prev = next;
        }
    }

    int result[N + 1];
    memset(result, 0, sizeof(result));
    topology_sort(adj, in_degree, result, N);

    if (result[N] == 0) {
        cout << 0 << endl;
    } else {
        for (int i = 1; i <= N; ++i) {
            cout << result[i] << endl;
        }
    }

    return 0;
}

void topology_sort(vector<int> adj[], int in_degree[], int result[], int N) {
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (q.empty()) {
            return;
        }

        int now = q.front();
        result[i] = now;
        q.pop();
        int size = adj[now].size();
        for (int idx = 0; idx < size; ++idx) {
            int next = adj[now][idx];
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }
}