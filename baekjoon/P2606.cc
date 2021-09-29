#include <iostream>

using namespace std;

#define endl '\n'

int _find(int parents[], int x);
void _union(int parents[], int x, int y);

/**
 * @see [바이러스](https://www.acmicpc.net/problem/2606)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int pc_count, edge_count;
    cin >> pc_count >> edge_count;
    int parents[pc_count + 1];
    for (int i = 1; i <= pc_count; ++i) {
        parents[i] = i;
    }
    for (int i = 0; i < edge_count; ++i) {
        int a_pc, b_pc;
        cin >> a_pc >> b_pc;
        _union(parents, a_pc, b_pc);
    }
    int count = 0;
    for (int i = 2; i <= pc_count; ++i) {
        if (_find(parents, 1) == _find(parents, i)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

int _find(int parents[], int x) {
    if (parents[x] == x) {
        return x;
    } else {
        return parents[x] = _find(parents, parents[x]);
    }
}

void _union(int parents[], int x, int y) {
    x = _find(parents, x);
    y = _find(parents, y);
    parents[y] = x;
}