#include <iostream>
#include <stack>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    int perm[N];
    for (int i = 0; i < N; ++i) {
        cin >> perm[i];
    }

    int NGE[N];
    stack<int> st;
    for (int i = N - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= perm[i]) {
            st.pop();
        }
        NGE[i] = st.empty() ? -1 : st.top();
        st.push(perm[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << NGE[i] << ' ';
    }

    return 0;
}