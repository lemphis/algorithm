#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::string;
using std::to_string;

/**
 * @see [수 이어 쓰기 2](https://www.acmicpc.net/problem/1790)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long N, k, num_count = 1, unit = 9, now = 0;
    cin >> N >> k;
    while (k > num_count * unit) {
        k -= (num_count * unit);
        now += unit;
        num_count++;
        unit *= 10;
    }
    now = (now + 1) + (k - 1) / num_count;
    string target = to_string(now);
    if (now > N)
        cout << -1 << endl;
    else
        cout << target[(k - 1) % num_count] << endl;
}