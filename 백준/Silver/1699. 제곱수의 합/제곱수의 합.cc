#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 100'001;
int memo[MAX] = {0};

int main() {
    fastio;
    int N;
    cin >> N;
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= N; ++i) {
        memo[i] = i;
        for (int j = 1; j * j <= i; ++j) {
            memo[i] = min(memo[i], memo[i - j * j] + 1);
        }
    }

    cout << memo[N];

    return 0;
}