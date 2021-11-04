#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

#define endl '\n'

/**
 * @see [히스토그램](https://www.acmicpc.net/problem/1725)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    int histogram[n];
    for (int i = 0; i < n; ++i) {
        cin >> histogram[i];
    }

    stack<int> idx_st;
    long long max_width = 0;
    for (int i = 0; i < n; ++i) {
        while (!idx_st.empty() && histogram[idx_st.top()] > histogram[i]) {
            int height = histogram[idx_st.top()];
            idx_st.pop();
            int width = i;
            if (!idx_st.empty()) {
                width = i - idx_st.top() - 1;
            }
            max_width = max(max_width, (long long)height * width);
        }
        idx_st.push(i);
    }

    while (!idx_st.empty()) {
        int height = histogram[idx_st.top()];
        idx_st.pop();
        int width = n;
        if (!idx_st.empty()) {
            width = n - idx_st.top() - 1;
        }
        max_width = max(max_width, (long long)height * width);
    }

    cout << max_width << endl;

    return 0;
}