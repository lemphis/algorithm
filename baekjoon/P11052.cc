#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [카드 구매하기](https://www.acmicpc.net/problem/11052)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int price[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> price[i];
    }

    int memo[N];
    for (int i = 1; i <= N; ++i) {
        memo[i] = price[i];
        for (int j = 1; j < i; ++j) {
            memo[i] = max(memo[i], memo[i - j] + price[j]);
        }
    }

    cout << memo[N] << endl;

    return 0;
}