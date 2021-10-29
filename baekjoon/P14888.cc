#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

void dfs(int nums[], int operators[], int depth, int N, int result, bool visited[], int& max_value, int& min_value);

/**
 * @see [연산자 끼워넣기](https://www.acmicpc.net/problem/14888)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    int operators[N - 1];
    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        int operator_count;
        cin >> operator_count;
        for (int temp_idx = 0; temp_idx < operator_count; ++temp_idx) {
            operators[idx + temp_idx] = i;
        }
        idx += operator_count;
    }

    bool visited[N - 1];
    memset(visited, 0, sizeof(visited));
    int max_value = -(0xffffffff >> 1) - 1, min_value = 0xffffffff >> 1;

    dfs(nums, operators, 0, N, nums[0], visited, max_value, min_value);

    cout << max_value << endl;
    cout << min_value << endl;

    return 0;
}

void dfs(int nums[], int operators[], int depth, int N, int result, bool visited[], int& max_value, int& min_value) {
    if (depth == N - 1) {
        if (result > max_value) {
            max_value = result;
        }
        if (result < min_value) {
            min_value = result;
        }

        return;
    }

    for (int i = 0; i < N - 1; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            switch (operators[i]) {
                case 0:
                    dfs(nums, operators, depth + 1, N, result + nums[depth + 1], visited, max_value, min_value);
                    break;
                case 1:
                    dfs(nums, operators, depth + 1, N, result - nums[depth + 1], visited, max_value, min_value);
                    break;
                case 2:
                    dfs(nums, operators, depth + 1, N, result * nums[depth + 1], visited, max_value, min_value);
                    break;
                case 3:
                    dfs(nums, operators, depth + 1, N, result / nums[depth + 1], visited, max_value, min_value);
                    break;
            }
            visited[i] = false;
        }
    }
}