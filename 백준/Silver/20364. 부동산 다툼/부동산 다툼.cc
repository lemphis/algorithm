#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, Q;
    cin >> N >> Q;
    vector<bool> occupied(N + 1, false);
    while (Q--) {
        int x;
        cin >> x;
        vector<int> path;
        int cur = x;
        while (cur > 0) {
            path.push_back(cur);
            cur /= 2;
        }

        int blocked = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            if (occupied[path[i]]) {
                blocked = path[i];
                break;
            }
        }

        if (blocked == 0) {
            occupied[x] = true;
            cout << 0 << endl;
        } else {
            cout << blocked << endl;
        }
    }

    return 0;
}