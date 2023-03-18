#include <iostream>
#include <stack>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;
    int N;
    cin >> N;

    long total = 0;
    stack<pii> st;
    for (int i = 0; i < N; ++i) {
        pii cow = {0, i};
        cin >> cow.first;
        while (!st.empty() && st.top().first < cow.first) {
            total += (cow.second - st.top().second + 1);
            st.pop();
        }
        if (!st.empty()) {
            total += (cow.second - st.top().second + 1);
        }
        st.push(cow);
    }

    cout << total;

    return 0;
}