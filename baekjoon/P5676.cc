#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'

int init_tree(int nums[], int seg_tree[], int node, int start, int end);
int get_mul(int seg_tree[], int node, int start, int end, int left, int right);
int update_tree(int seg_tree[], int node, int start, int end, int target, int next_value);
int convert(int num);

/**
 * @see [음주 코딩](https://www.acmicpc.net/problem/5676)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    while (cin >> N >> K) {
        int nums[N];
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }

        int tree_height = (int)ceil(log2(N));
        int seg_tree[1 << (tree_height + 1)];

        init_tree(nums, seg_tree, 1, 0, N - 1);

        string result;
        while (K--) {
            char command;
            int i, j;
            cin >> command >> i >> j;
            if (command == 'C') {
                update_tree(seg_tree, 1, 0, N - 1, i - 1, j);
            } else {
                int answer = get_mul(seg_tree, 1, 0, N - 1, i - 1, j - 1);
                if (answer > 0)
                    result += '+';
                else if (answer < 0)
                    result += '-';
                else
                    result += '0';
            }
        }

        cout << result << endl;
    }

    return 0;
}

int init_tree(int nums[], int seg_tree[], int node, int start, int end) {
    if (start == end) {
        return seg_tree[node] = convert(nums[start]);
    }

    int mid = (start + end) >> 1;
    return seg_tree[node] = convert(init_tree(nums, seg_tree, node * 2, start, mid)) * convert(init_tree(nums, seg_tree, node * 2 + 1, mid + 1, end));
}

int get_mul(int seg_tree[], int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }

    if (left <= start && right >= end) {
        return seg_tree[node];
    }

    int mid = (start + end) >> 1;
    return convert(get_mul(seg_tree, node * 2, start, mid, left, right)) * convert(get_mul(seg_tree, node * 2 + 1, mid + 1, end, left, right));
}

int update_tree(int seg_tree[], int node, int start, int end, int target, int next_value) {
    if (start > target || end < target) {
        return seg_tree[node];
    }

    if (start == end && start == target) {
        return seg_tree[node] = convert(next_value);
    }

    int mid = (start + end) >> 1;
    return seg_tree[node] = convert(update_tree(seg_tree, node * 2, start, mid, target, next_value)) * convert(update_tree(seg_tree, node * 2 + 1, mid + 1, end, target, next_value));
}

int convert(int num) {
    if (num > 0) {
        return 1;
    }
    if (num < 0) {
        return -1;
    }
    return 0;
}