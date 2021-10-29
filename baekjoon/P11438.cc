#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'

int init(int nums[], int tree[], int node, int start, int end);
int select(int tree[], int node, int start, int end, int left, int right);
int update(int tree[], int node, int start, int end, int idx, int new_value);

/**
 * @see [수열과 쿼리 17](https://www.acmicpc.net/problem/14438)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int height = ceil(log2(N));
    int tree[1 << (height + 1)];
    init(nums, tree, 1, 0, N - 1);

    int M;
    cin >> M;

    while (M--) {
        int command, i, j;
        cin >> command >> i >> j;
        if (command == 1) {
            update(tree, 1, 0, N - 1, i - 1, j);
        } else {
            cout << select(tree, 1, 0, N - 1, i - 1, j - 1) << endl;
        }
    }

    return 0;
}

int init(int nums[], int tree[], int node, int start, int end) {
    if (start == end) {
        return tree[node] = nums[start];
    }

    int mid = (start + end) >> 1;
    return tree[node] = min(init(nums, tree, node * 2, start, mid), init(nums, tree, node * 2 + 1, mid + 1, end));
}

int select(int tree[], int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0xffffffff >> 1;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    return min(select(tree, node * 2, start, mid, left, right), select(tree, node * 2 + 1, mid + 1, end, left, right));
}

int update(int tree[], int node, int start, int end, int idx, int new_value) {
    if (idx > end || idx < start) {
        return tree[node];
    }

    if (start == end && start == idx) {
        return tree[node] = new_value;
    }

    int mid = (start + end) >> 1;
    return tree[node] = min(update(tree, node * 2, start, mid, idx, new_value), update(tree, node * 2 + 1, mid + 1, end, idx, new_value));
}