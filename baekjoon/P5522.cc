#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [카드 게임](https://www.acmicpc.net/problem/5522)
 */
int main() {
    fastio;
    int score, sum = 0;
    while (cin >> score) {
        sum += score;
    }

    cout << sum << endl;

    return 0;
}