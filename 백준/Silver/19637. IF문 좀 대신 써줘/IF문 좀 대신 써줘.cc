#include <iostream>
#include <algorithm>
#include <map>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pis = pair<int, string>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    map<int, string> arr;
    for (int i = 0; i < n; i++) {
        int x; string y;
        cin >> y >> x;
        arr.insert(pis(x, y));
    }
    map<int, string>::iterator iter;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        iter = arr.lower_bound(x);
        cout << iter->second << endl;
    }
    return 0;
}
