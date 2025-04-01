#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    if (N < 3) {
        cout << N;
        return 0;
    }

    sort(heights.begin(), heights.end());

    stack<int> l, r;
    l.push(heights[0]);
    r.push(heights[1]);
    for (int i = 2; i < N; ++i) {
        if (i & 1) {
            if (r.top() < heights[i]) {
                r.push(heights[i]);
            }
        } else {
            if (l.top() < heights[i]) {
                l.push(heights[i]);
            }
        }
    }

    cout << (l.size() + r.size());

    return 0;
}