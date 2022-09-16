#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int, int, vector<string>&);

int main() {
    fastio;
    int R, C;
    cin >> R >> C;
    vector<string> items(R);
    for (int i = 0; i < R; ++i) {
        cin >> items[i];
    }
    int lo = 0, hi = R;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, C, items))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;

    return 0;
}

bool check(int start, int col, vector<string>& items) {
    set<string> set;
    for (int i = 0; i < col; ++i) {
        string s;
        for (int j = start; j < items.size(); ++j) {
            s += items[j][i];
        }
        set.insert(s);
    }
    return set.size() == col;
}