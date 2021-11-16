#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define endl '\n'
#define MAX 1'000'001

/**
 * @see [오등큰수](https://www.acmicpc.net/problem/17299)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N], F[MAX], NGF[N];
    memset(F, 0, sizeof(F));
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        ++F[nums[i]];
    }

    stack<int> st;
    for (int i = N - 1; i >= 0; --i) {
        if (!st.empty()) {
            while (!st.empty() && F[st.top()] <= F[nums[i]]) {
                st.pop();
            }
        }

        NGF[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << NGF[i] << ' ';
    }

    return 0;
}