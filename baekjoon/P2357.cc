#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'

int init(int nums[], int tree[], int node, int start, int end, bool is_min);
int query(int tree[], int node, int start, int end, int left, int right, bool is_min);

/**
 * @see [최솟값과 최댓값](https://www.acmicpc.net/problem/2357)
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
    int min_tree[1 << (height + 1)];
    int max_tree[1 << (height + 1)];
    init(nums, min_tree, 1, 0, N - 1, true);
    init(nums, max_tree, 1, 0, N - 1, false);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << query(min_tree, 1, 0, N - 1, a - 1, b - 1, true) << ' ' << query(max_tree, 1, 0, N - 1, a - 1, b - 1, false) << endl;
    }

    return 0;
}

int init(int nums[], int tree[], int node, int start, int end, bool is_min) {
    if (start == end) {
        return tree[node] = nums[start];
    }

    int mid = (start + end) >> 1;
    int left_tree = init(nums, tree, node * 2, start, mid, is_min);
    int right_tree = init(nums, tree, node * 2 + 1, mid + 1, end, is_min);

    return tree[node] = is_min ? min(left_tree, right_tree) : max(left_tree, right_tree);
}

int query(int tree[], int node, int start, int end, int left, int right, bool is_min) {
    if (left > end || right < start) {
        return is_min ? 0xffffffff >> 1 : 0;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    int left_tree = query(tree, node * 2, start, mid, left, right, is_min);
    int right_tree = query(tree, node * 2 + 1, mid + 1, end, left, right, is_min);

    return is_min ? min(left_tree, right_tree) : max(left_tree, right_tree);
}