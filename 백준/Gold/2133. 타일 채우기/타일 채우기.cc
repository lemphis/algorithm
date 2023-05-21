#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 30;

int main() {
    fastio;
    int N;
    cin >> N;
    if (N & 1) {
        cout << 0 << endl;
        return 0;
    }

    int memo[MAX + 1];
    memo[0] = 1;
    memo[2] = 3;
    for (int i = 4; i <= MAX; i += 2) {
        memo[i] = memo[i - 2] * 3;
        for (int j = 4; j <= i; j += 2) {
            memo[i] += memo[i - j] * 2;
        }
    }

    cout << memo[N] << endl;

    return 0;
}