#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

int sum(int tree[], int idx);
void update(int tree[], int idx, int diff, int N);

/**
 * @see [구간 합 구하기 4](https://www.acmicpc.net/problem/11659)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int nums[N + 1];
    int tree[N + 1];
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
        update(tree, i, nums[i], N);
    }

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << sum(tree, j) - sum(tree, i - 1) << endl;
    }

    return 0;
}

int sum(int tree[], int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += tree[idx];
        idx -= (idx & -idx);
    }

    return ans;
}

void update(int tree[], int idx, int diff, int N) {
    while (idx <= N) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}