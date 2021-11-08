#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

void topology_sort(vector<int> graph[], int in_degree[], int result[], int N);

/**
 * @see [줄 세우기](https://www.acmicpc.net/problem/2252)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> graph[N];
    int in_degree[N];
    int result[N];
    memset(in_degree, 0, sizeof(in_degree));
    while (M--) {
        int A, B;
        cin >> A >> B;
        graph[A - 1].push_back(B - 1);

        ++in_degree[B - 1];
    }

    topology_sort(graph, in_degree, result, N);

    for (int i = 0; i < N; ++i) {
        cout << result[i] + 1 << ' ';
        
    }

    return 0;
}

void topology_sort(vector<int> graph[], int in_degree[], int result[], int N) {
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (q.empty()) {
            return;
        }
        result[i] = q.front();
        q.pop();
        for (int idx = 0; idx < graph[result[i]].size(); ++idx) {
            int vertex = graph[result[i]][idx];
            if (--in_degree[vertex] == 0) {
                q.push(vertex);
            }
        }
    }
}