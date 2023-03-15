#include <iostream>
#include <stack>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N;
    cin >> N;
    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    stack<int> st;
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        while (!st.empty() && st.top() <= h[i]) {
            st.pop();
        }
        total += (ll)st.size();
        st.push(h[i]);
    }

    cout << total;

    return 0;
}