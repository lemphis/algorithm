#include <iostream>
#include <utility>

using namespace std;

using pii = pair<int, int>;

#define endl '\n'
#define INF 1e9
#define MAX 300

pii node[MAX];
int min_dist[MAX][MAX];

void floyd_warshall(int n);

/**
 * @see [Line Friends (Small)](https://www.acmicpc.net/problem/14588)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> node[i].first >> node[i].second;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                min_dist[i][j] = 0;
            } else {
                if (node[i].first > node[j].second || node[j].first > node[i].second) {
                    min_dist[i][j] = INF;
                } else {
                    min_dist[i][j] = 1;
                }
            }
        }
    }

    floyd_warshall(N);

    int Q;
    cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        cout << (min_dist[A - 1][B - 1] == INF ? -1 : min_dist[A - 1][B - 1]) << endl;
    }

    return 0;
}

void floyd_warshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i == k || j == k) continue;
                if (min_dist[i][j] > min_dist[i][k] + min_dist[k][j]) {
                    min_dist[i][j] = min_dist[i][k] + min_dist[k][j];
                }
            }
        }
    }
}