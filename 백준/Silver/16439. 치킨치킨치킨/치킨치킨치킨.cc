#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 30;
int chicken[MAX][MAX];

void go(int N, int M, int idx, int depth, int& sum, int chicken_idx[]);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> chicken[r][c];
        }
    }

    int chicken_idx[3];
    int sum = 0;
    go(N, M, 0, 0, sum, chicken_idx);

    cout << sum;

    return 0;
}

void go(int N, int M, int idx, int depth, int& sum, int chicken_idx[]) {
    if (N == 1) {
        sum = *max_element(chicken[0], chicken[0] + M);
        return;
    } else if (N == 2) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < M; ++k) {
                if (j != k) {
                    sum = max(sum, chicken[0][j] + chicken[1][k]);
                }
            }
        }
        return;
    } else {
        if (depth == 3) {
            int total = 0;
            for (int i = 0; i < N; ++i) {
                int temp = 0;
                for (int j = 0; j < 3; ++j) {
                    temp = max(temp, chicken[i][chicken_idx[j]]);
                }
                total += temp;
            }
            sum = max(sum, total);
            return;
        }
        for (int i = idx; i < M; ++i) {
            chicken_idx[depth] = i;
            go(N, M, i, depth + 1, sum, chicken_idx);
        }
    }
}