#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

long dfs(int num[], int size, int idx, int sum);

long memo[101][21];

int main() {
    fastio;
    int N;
    cin >> N;
    int num[N];
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << dfs(num, N, 0, num[0]);

    return 0;
}

long dfs(int num[], int size, int idx, int sum) {
    if (sum < 0 || sum > 20) {
        return 0;
    }
    if (idx == size - 2) {
        return num[size - 1] == sum ? 1 : 0;
    }
    if (memo[idx][sum] > -1) {
        return memo[idx][sum];
    }

    memo[idx][sum] = 0;

    return memo[idx][sum] += (dfs(num, size, idx + 1, sum + num[idx + 1]) + dfs(num, size, idx + 1, sum - num[idx + 1]));
}