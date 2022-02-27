#include <iostream>
#include <stack>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [좋은 단어](https://www.acmicpc.net/problem/3986)
 */
int main() {
    fastio;
    int N;
    cin >> N;

    int count = 0;
    while (N--) {
        string word;
        cin >> word;
        stack<char> st;
        for (int i = 0; i < word.length(); ++i) {
            if (!st.empty() && st.top() == word[i]) {
                st.pop();
            } else {
                st.push(word[i]);
            }
        }

        if (st.size() == 0) {
            count++;
        }
    }

    cout << count;

    return 0;
}