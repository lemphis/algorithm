#include <iostream>
#include <unordered_set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    unordered_set<string> pset;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        string s2;
        for (int i = 0; i < s.size(); i++) {
            s2 += s[i];
            pset.insert(s2);
        }
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (pset.find(s) != pset.end()) {
            ++res;
        }
    }

    cout << res;

    return 0;
}