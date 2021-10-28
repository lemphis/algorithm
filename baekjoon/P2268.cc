#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

using ll = long long;

#define endl '\n'

ll select(ll tree[], int node, int start, int end, int left, int right);
ll update(ll tree[], int node, int start, int end, int idx, int new_value);

/**
 * @see [수들의 합](https://www.acmicpc.net/problem/2268)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int nums[N];
    memset(nums, 0, sizeof(nums));

    int height = ceil(log2(N));
    ll tree[1 << (height + 1)];
    memset(tree, 0, sizeof(tree));

    while (M--) {
        int func, i, j;
        cin >> func >> i >> j;
        if (func == 0) {
            if (i > j) {
                swap(i, j);
            }
            cout << select(tree, 1, 0, N - 1, i - 1, j - 1) << endl;
        } else {
            update(tree, 1, 0, N - 1, i - 1, j);
        }
    }

    return 0;
}

ll select(ll tree[], int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    return select(tree, node * 2, start, mid, left, right) + select(tree, node * 2 + 1, mid + 1, end, left, right);
}

ll update(ll tree[], int node, int start, int end, int idx, int new_value) {
    if (idx > end || idx < start) {
        return tree[node];
    }

    if (start == end && start == idx) {
        return tree[node] = new_value;
    }

    int mid = (start + end) >> 1;
    return tree[node] = update(tree, node * 2, start, mid, idx, new_value) + update(tree, node * 2 + 1, mid + 1, end, idx, new_value);
}