#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<pair<string, string>> v(N);
    for (auto& [mentor, mentee] : v) {
        cin >> mentor >> mentee;
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b) -> bool {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for (auto& [mentor, mentee] : v) {
        cout << mentor << ' ' << mentee << endl;
    }

    return 0;
}