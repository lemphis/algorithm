#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int H, W;
    cin >> H >> W;

    int heights[W];
    for (int i = 0; i < W; ++i) {
        cin >> heights[i];
    }

    int left = heights[0];
    int total_count = 0;
    for (int i = 1; i < W - 1; ++i) {
        if (heights[i] > left) {
            left = heights[i];
            continue;
        }
        int right = *max_element(heights + i + 1, heights + W);
        if (heights[i] > min(left, right)) {
            continue;
        }
        total_count += min(left, right) - heights[i];
    }

    cout << total_count;

    return 0;
}