#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

void dfs(int N, int prev_idx, int depth, int sum, int nums[], bool visited[], int& max_sum);

/**
 * @see [차이를 최대로](https://www.acmicpc.net/problem/10819)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    bool visited[N];
    memset(visited, 0, sizeof(visited));
    int max_sum = 0;
    for (int i = 0; i < N; ++i) {
        visited[i] = true;
        dfs(N, i, 0, 0, nums, visited, max_sum);
        visited[i] = false;
    }

    cout << max_sum << endl;
    return 0;
}

void dfs(int N, int prev_idx, int depth, int sum, int nums[], bool visited[], int& max_sum) {
    if (depth == N - 1) {
        if (max_sum < sum) {
            max_sum = sum;
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            int diff = abs(nums[prev_idx] - nums[i]);
            sum += diff;
            dfs(N, i, depth + 1, sum, nums, visited, max_sum);
            visited[i] = false;
            sum -= diff;
        }
    }
}