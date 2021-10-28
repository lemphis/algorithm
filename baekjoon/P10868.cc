#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'

int init(int nums[], int tree[], int node, int start, int end);
int query(int tree[], int node, int start, int end, int left, int right);

/**
 * @see [최솟값](https://www.acmicpc.net/problem/10868)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int height = (int)ceil(log2(N));
    int tree[1 << (height + 1)];
    init(nums, tree, 1, 0, N - 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << query(tree, 1, 0, N - 1, a - 1, b - 1) << endl;
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

int query(int tree[], int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INT_MAX;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    return min(query(tree, node * 2, start, mid, left, right), query(tree, node * 2 + 1, mid + 1, end, left, right));
}