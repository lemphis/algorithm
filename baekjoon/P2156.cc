#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [포도주 시식](https://www.acmicpc.net/problem/2156)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int weight[n], memo[n];
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    int max_weight = 0;
    if (n == 1) {
        max_weight = weight[n - 1];
    } else if (n == 2) {
        max_weight = weight[n - 1] + weight[n - 2];
    } else {
        memo[0] = weight[0];
        memo[1] = weight[0] + weight[1];
        memo[2] = max(max(weight[0] + weight[1], weight[1] + weight[2]), weight[0] + weight[2]);
        max_weight = memo[2];
        for (int i = 3; i < n; ++i) {
            memo[i] = max(max(memo[i - 3] + weight[i - 1], memo[i - 2]) + weight[i], memo[i - 1]);
            max_weight = max(max_weight, memo[i]);
        }
    }

    cout << max_weight << endl;

    return 0;
}