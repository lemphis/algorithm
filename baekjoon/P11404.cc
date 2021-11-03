#include <iostream>

using namespace std;

#define endl '\n'
#define INF 1e9
#define MAX 100

int min_dist[MAX][MAX];

void floyd_warshall(int n);

/**
 * @see [플로이드](https://www.acmicpc.net/problem/11404)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            min_dist[i][j] = i == j ? 0 : INF;
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (min_dist[a - 1][b - 1] > c) {
            min_dist[a - 1][b - 1] = c;
        }
    }

    floyd_warshall(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (min_dist[i][j] == INF ? 0 : min_dist[i][j]) << ' ';
        }
        cout << endl;
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