#include <iostream>

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [배열 합치기](https://www.acmicpc.net/problem/11728)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int n_items[N], m_items[M], sorted_items[N + M];
    for (int i = 0; i < N; ++i) cin >> n_items[i];
    for (int i = 0; i < M; ++i) cin >> m_items[i];
    int i = 0, j = 0;
    int idx = 0;
    while (i < N && j < M) {
        if (n_items[i] <= m_items[j])
            sorted_items[idx++] = n_items[i++];
        else
            sorted_items[idx++] = m_items[j++];
    }
    while (i < N) sorted_items[idx++] = n_items[i++];
    while (j < M) sorted_items[idx++] = m_items[j++];
    for (int i = 0; i < N + M; ++i) {
        cout << sorted_items[i] << ' ';
    }
}