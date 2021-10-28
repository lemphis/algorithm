#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'
#define DIVISOR 1'000'000'007

using ll = long long;

int init_tree(int nums[], int seg_tree[], int node, int start, int end);
int get_mul(int seg_tree[], int node, int start, int end, int left, int right);
int update_tree(int seg_tree[], int node, int start, int end, int target, int next_value);

/**
 * @see [구간 곱 구하기](https://www.acmicpc.net/problem/11505)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    int nums[N];
    int tree_height = (int)ceil(log2(N));
    int seg_tree[1 << (tree_height + 1)];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    init_tree(nums, seg_tree, 1, 0, N - 1);

    for (int i = 0; i < M + K; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update_tree(seg_tree, 1, 0, N - 1, b - 1, c);
            nums[b - 1] = c;
        } else {
            cout << get_mul(seg_tree, 1, 0, N - 1, b - 1, c - 1) << endl;
        }
    }

    return 0;
}

int init_tree(int nums[], int seg_tree[], int node, int start, int end) {
    if (start == end) {
        return seg_tree[node] = nums[start];
    }

    int mid = (start + end) >> 1;
    return seg_tree[node] = ((ll)(init_tree(nums, seg_tree, node * 2, start, mid) % DIVISOR) * (ll)(init_tree(nums, seg_tree, node * 2 + 1, mid + 1, end)) % DIVISOR) % DIVISOR;
}

int get_mul(int seg_tree[], int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }

    if (left <= start && right >= end) {
        return seg_tree[node];
    }

    int mid = (start + end) >> 1;
    return ((ll)get_mul(seg_tree, node * 2, start, mid, left, right) % DIVISOR) * (ll)(get_mul(seg_tree, node * 2 + 1, mid + 1, end, left, right) % DIVISOR) % DIVISOR;
}

int update_tree(int seg_tree[], int node, int start, int end, int target, int next_value) {
    if (start > target || end < target) {
        return seg_tree[node];
    }

    if (start == end && start == target) {
        return seg_tree[node] = next_value;
    }

    int mid = (start + end) >> 1;
    return seg_tree[node] = ((ll)update_tree(seg_tree, node * 2, start, mid, target, next_value) % DIVISOR) * (ll)(update_tree(seg_tree, node * 2 + 1, mid + 1, end, target, next_value) % DIVISOR) % DIVISOR;
}