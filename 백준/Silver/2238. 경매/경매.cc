#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int U, N;
    cin >> U >> N;
    vector<vector<string>> people(U + 1);
    for (int i = 0; i < N; ++i) {
        string S;
        int P;
        cin >> S >> P;
        people[P].push_back(S);
    }

    int min_len = 1e9;
    for (auto& item : people) {
        if (!item.empty() && min_len > item.size()) {
            min_len = item.size();
        }
    }

    for (int i = 1; i <= U; ++i) {
        if (people[i].size() == min_len) {
            cout << people[i][0] << ' ' << i;
            break;
        }
    }

    return 0;
}