#include <iostream>
#include <stack>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    string s;
    cin >> s;
    stack<char> st;
    int idx = 0;
    int ans = 0;
    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else {
            if (st.empty()) {
                ++ans;
            } else {
                st.pop();
            }
        }
    }

    cout << ans + st.size();

    return 0;
}