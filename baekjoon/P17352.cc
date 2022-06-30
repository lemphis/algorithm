#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 300'000;
int parent[MAX];

int _find(int x);
void _union(int x, int y);
void print_ans(int N);

/**
 * @see [여러분의 다리가 되어 드리겠습니다!](https://www.acmicpc.net/problem/17352)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) parent[i] = i;
    for (int i = 0; i < N - 2; ++i) {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    print_ans(N);

    return 0;
}

int _find(int x) {
    return x == parent[x] ? x : (parent[x] = _find(parent[x]));
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    x < y ? parent[y] = x : parent[x] = y;
}

void print_ans(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (_find(i) != _find(j)) {
                cout << i + 1 << ' ' << j + 1 << endl;
                return;
            }
        }
    }
}