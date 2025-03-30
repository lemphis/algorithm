#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& levels, int start, int end, int level);

int main() {
    fastio;
    int K;
    cin >> K;
    int n = (1 << K) - 1;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> levels(K);
    dfs(nums, levels, 0, n - 1, 0);

    for (const auto& level : levels) {
        for (auto node : level) {
            cout << node << ' ';
        }
        cout << endl;
    }

    return 0;
}

void dfs(vector<int>& nums, vector<vector<int>>& levels, int start, int end, int level) {
    if (start > end) {
        return;
    }
    int mid = (start + end) / 2;
    levels[level].push_back(nums[mid]);
    dfs(nums, levels, start, mid - 1, level + 1);
    dfs(nums, levels, mid + 1, end, level + 1);
}