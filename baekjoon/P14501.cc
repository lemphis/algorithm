#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [퇴사](https://www.acmicpc.net/problem/14501)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    int time[N], price[N], memo[N];
    for (int i = 0; i < N; ++i) {
        cin >> time[i] >> price[i];
    }

    memo[N - 1] = time[N - 1] == 1 ? price[N - 1] : 0;
    int max_profit = memo[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        if (i + time[i] > N)
            memo[i] = memo[i + 1];
        else if (i + time[i] == N)
            memo[i] = max(price[i], memo[i + 1]);
        else
            memo[i] = *max_element(memo + i + time[i], memo + N) + price[i];

        max_profit = max(max_profit, memo[i]);
    }

    cout << max_profit << endl;

    return 0;
}