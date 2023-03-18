#include <iostream>
#include <stack>
#include <utility>

using namespace std;

using pii = pair<int, int>;

#define endl '\n'

/**
 * @see [오아시스 재결합](https://www.acmicpc.net/problem/3015)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int people[N];
    for (int i = 0; i < N; ++i) {
        cin >> people[i];
    }

    stack<pii> st;
    long long max_count = 0;
    for (int i = 0; i < N; ++i) {
        pii target = {people[i], 1};
        if (!st.empty()) {
            while (!st.empty() && st.top().first <= target.first) {
                if (target.first == st.top().first) {
                    target.second += st.top().second;
                }
                max_count += st.top().second;
                st.pop();
            }
        }

        if (!st.empty()) ++max_count;
        st.push(target);
    }

    cout << max_count << endl;

    return 0;
}