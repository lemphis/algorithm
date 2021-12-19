#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 40

/**
 * @see [극장 좌석](https://www.acmicpc.net/problem/2302)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int VIP[M];
    for (int i = 0; i < M; ++i) {
        cin >> VIP[i];
    }

    int memo[MAX + 1];
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i <= MAX; ++i) {
        memo[i] = memo[i - 2] + memo[i - 1];
    }

    if (M == 0) {
        cout << memo[N] << endl;
        return 0;
    }

    int sum = 1;
    for (int i = 0; i < M; ++i) {
        if (i == 0) {
            sum *= memo[VIP[i] - 1];
        } else {
            sum *= memo[VIP[i] - VIP[i - 1] - 1];
        }
    }

    sum *= memo[N - VIP[M - 1]];

    cout << sum << endl;

    return 0;
}