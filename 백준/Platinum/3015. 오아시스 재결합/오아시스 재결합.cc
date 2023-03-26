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
    while (N--) {
        pii people = {0, 1};
        cin >> people.first;
        while (!st.empty() && st.top().first <= people.first) {
            if (st.top().first == people.first) {
                people.second += st.top().second;
            }
            total += st.top().second;
            st.pop();
        }
        if (!st.empty()) {
            ++total;
        }
        st.push(people);
    }

    cout << total;

    return 0;
}