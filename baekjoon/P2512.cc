#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int N, int M, int budgets[]);

/**
 * @see [예산](https://www.acmicpc.net/problem/2512)
 */
int main() {
    fastio;
    int N, M;
    cin >> N;
    int budgets[N];
    int max_budget = 0;
    for (int i = 0; i < N; ++i) {
        cin >> budgets[i];
        max_budget = max(max_budget, budgets[i]);
    }
    cin >> M;

    int lo = 0, hi = max_budget + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, N, M, budgets))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;

    return 0;
}

bool check(int target, int N, int M, int budgets[]) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += min(target, budgets[i]);
    }

    return sum <= M;
}