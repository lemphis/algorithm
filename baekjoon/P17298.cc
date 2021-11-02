#include <iostream>
#include <stack>

using namespace std;

#define endl '\n'

/**
 * @see [오큰수](https://www.acmicpc.net/problem/17298)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int perm[N];
    for (int i = 0; i < N; ++i) {
        cin >> perm[i];
    }

    stack<int> st;
    int NGE[N];
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