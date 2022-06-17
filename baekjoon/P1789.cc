#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;

/**
 * @see [수들의 합](https://www.acmicpc.net/problem/1789)
 */
int main() {
    fastio;
    ll S;
    cin >> S;

    ll sum = 0;
    int answer = 0;
    for (int i = 1; sum <= S; ++i) {
        sum += i;
        answer++;
    }

    cout << answer - 1 << endl;

    return 0;
}