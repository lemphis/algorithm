#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int N, int M, int pivot, int tree[]);

/**
 * @see [랜선 자르기](https://www.acmicpc.net/problem/2805)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int tree[N];
    for (int i = 0; i < N; ++i) {
        cin >> tree[i];
    }

    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(N, M, mid, tree))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;

    return 0;
}

bool check(int N, int M, int pivot, int tree[]) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        if (tree[i] > pivot) {
            sum += tree[i] - pivot;
        }
    }

    return sum >= M;
}