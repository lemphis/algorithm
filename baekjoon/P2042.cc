#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'

long long init_tree(long long nums[], long long seg_tree[], int node, int start, int end);
long long get_sum(long long seg_tree[], int node, int start, int end, int left, int right);
void update_tree(long long seg_tree[], int node, int start, int end, int target, long long diff);

/**
 * @see [구간 합 구하기](https://www.acmicpc.net/problem/2042)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    long long nums[N];
    int tree_height = (int)ceil(log2(N));
    long long seg_tree[1 << (tree_height + 1)];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    init_tree(nums, seg_tree, 1, 0, N - 1);

    for (int i = 0; i < M + K; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            update_tree(seg_tree, 1, 0, N - 1, b - 1, c - nums[b - 1]);
            nums[b - 1] = c;
        } else {
            cout << get_sum(seg_tree, 1, 0, N - 1, b - 1, c - 1) << endl;
        }
    }

    return 0;
}

long long init_tree(long long nums[], long long seg_tree[], int node, int start, int end) {
    if (start == end) {
        return seg_tree[node] = nums[start];
    }

    int mid = (start + end) >> 1;
    return seg_tree[node] = init_tree(nums, seg_tree, node * 2, start, mid) + init_tree(nums, seg_tree, node * 2 + 1, mid + 1, end);
}

long long get_sum(long long seg_tree[], int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && right >= end) {
        return seg_tree[node];
    }

    int mid = (start + end) >> 1;
    return get_sum(seg_tree, node * 2, start, mid, left, right) + get_sum(seg_tree, node * 2 + 1, mid + 1, end, left, right);
}

void update_tree(long long seg_tree[], int node, int start, int end, int target, long long diff) {
    if (start > target || end < target) {
        return;
    }

    seg_tree[node] += diff;

    int mid = (start + end) >> 1;
    if (start != end) {
        update_tree(seg_tree, node * 2, start, mid, target, diff);
        update_tree(seg_tree, node * 2 + 1, mid + 1, end, target, diff);
    }
}