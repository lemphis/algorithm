#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

#define endl '\n'

ll init(ll nums[], ll tree[], int node, int begin, int end);
void update_lazy(ll tree[], ll lazy[], int node, int begin, int end);
void update(ll tree[], ll lazy[], int node, int begin, int end, int update_begin, int update_end, ll diff);
ll query(ll tree[], ll lazy[], int node, int begin, int end, int query_begin, int query_end);

/**
 * @see [구간 합 구하기 2](https://www.acmicpc.net/problem/10999)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    ll nums[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
    }

    int height = (int)ceil(log2(N));
    int tree_size = 1 << (height + 1);
    ll tree[tree_size], lazy[tree_size];
    memset(lazy, 0, sizeof(lazy));

    init(nums, tree, 1, 1, N);

    for (int i = 0; i < M + K; ++i) {
        int a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(tree, lazy, 1, 1, N, b, c, d);
        } else {
            cin >> b >> c;
            cout << query(tree, lazy, 1, 1, N, b, c) << endl;
        }
    }

    return 0;
}

ll init(ll nums[], ll tree[], int node, int begin, int end) {
    if (begin == end) {
        return tree[node] = nums[begin];
    }

    int mid = (begin + end) >> 1;
    return tree[node] = init(nums, tree, node * 2, begin, mid) + init(nums, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(ll tree[], ll lazy[], int node, int begin, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - begin + 1) * lazy[node];
        if (begin != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(ll tree[], ll lazy[], int node, int begin, int end, int update_begin, int update_end, ll diff) {
    update_lazy(tree, lazy, node, begin, end);

    if (begin > update_end || end < update_begin) {
        return;
    }

    if (update_begin <= begin && end <= update_end) {
        tree[node] += (end - begin + 1) * diff;
        if (begin != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    int mid = (begin + end) >> 1;
    update(tree, lazy, node * 2, begin, mid, update_begin, update_end, diff);
    update(tree, lazy, node * 2 + 1, mid + 1, end, update_begin, update_end, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll tree[], ll lazy[], int node, int begin, int end, int query_begin, int query_end) {
    update_lazy(tree, lazy, node, begin, end);

    if (begin > query_end || end < query_begin) {
        return 0;
    }

    if (query_begin <= begin && query_end >= end) {
        return tree[node];
    }

    int mid = (begin + end) >> 1;
    return query(tree, lazy, node * 2, begin, mid, query_begin, query_end) + query(tree, lazy, node * 2 + 1, mid + 1, end, query_begin, query_end);
}