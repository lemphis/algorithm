#include <iostream>
#include <map>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 200'002;
int parent[MAX];

int _find(int x);
void _union(int x, int y);

/**
 * @see [친구 네트워크](https://www.acmicpc.net/problem/4195)
 */
int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
        map<string, int> st_i;
        map<int, int> i_i;
        int F;
        cin >> F;
        for (int i = 1; i < MAX; ++i) {
            parent[i] = i;
        }
        int idx = 1;
        while (F--) {
            string p1, p2;
            cin >> p1 >> p2;
            if (!st_i[p1]) {
                st_i[p1] = idx++;
                i_i[st_i[p1]] = 1;
            }
            if (!st_i[p2]) {
                st_i[p2] = idx++;
                i_i[st_i[p2]] = 1;
            }
            int p1_idx = _find(st_i[p1]);
            int p2_idx = _find(st_i[p2]);
            if (p1_idx != p2_idx) {
                int p1_value = i_i[p1_idx];
                int p2_value = i_i[p2_idx];
                i_i[p1_idx] += p2_value;
                i_i[p2_idx] += p1_value;
                _union(p1_idx, p2_idx);
            }

            cout << i_i[p1_idx] << endl;
        }
    }

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