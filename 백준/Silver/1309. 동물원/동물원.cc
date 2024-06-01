#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

typedef long long ll;

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> memo(n + 1, 0);
    memo[0] = 1;
    memo[1] = 3;
    for (int i = 2; i <= n; ++i) {
        memo[i] = (memo[i - 1] * 2 + memo[i - 2]) % 9901;
    }

    cout << memo[n];

    return 0;
}