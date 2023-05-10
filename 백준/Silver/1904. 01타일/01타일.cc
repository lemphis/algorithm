#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000'001;
int memo[MAX] = {0};

int main() {
    fastio;
    int N;
    cin >> N;
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i <= N; ++i) {
        memo[i] = (memo[i - 2] + memo[i - 1]) % 15'746;
    }

    cout << memo[N];

    return 0;
}