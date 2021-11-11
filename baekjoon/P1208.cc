#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

void dfs(vector<int>& items, int nums[], int sum, int start, int end);

/**
 * @see [부분수열의 합 2](https://www.acmicpc.net/problem/1208)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, S;
    cin >> N >> S;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> left, right;
    int mid = N / 2;
    dfs(left, nums, 0, 0, mid);
    dfs(right, nums, 0, mid, N);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), greater<>());

    size_t i = 0, j = 0;
    long long count = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] + right[j] > S) {
            j++;
        } else if (left[i] + right[j] < S) {
            i++;
        } else {
            int left_count = 1;
            int right_count = 1;
            ++i;
            ++j;
            while (i < left.size() && left[i] == left[i - 1]) {
                ++left_count;
                ++i;
            }
            while (j < right.size() && right[j] == right[j - 1]) {
                ++right_count;
                ++j;
            }
            count += (long long)left_count * right_count;
        }
    }

    if (S == 0) {
        --count;
    }

    cout << count << endl;

    return 0;
}

void dfs(vector<int>& items, int nums[], int sum, int start, int end) {
    if (start == end) {
        items.push_back(sum);
        return;
    }

    dfs(items, nums, sum + nums[start], start + 1, end);
    dfs(items, nums, sum, start + 1, end);
}