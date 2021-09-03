#include <algorithm>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::swap;

/**
 * @see [토너먼트](https://www.acmicpc.net/problem/1057)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, jimin, hansu, count = 1;
    cin >> n >> jimin >> hansu;
    if (jimin > hansu) swap(jimin, hansu);
    while ((jimin / 2 + 1) != (hansu / 2) || hansu - jimin != 1) {
        jimin = jimin % 2 == 0 ? jimin / 2 : jimin / 2 + 1;
        hansu = hansu % 2 == 0 ? hansu / 2 : hansu / 2 + 1;
        count++;
    }
    cout << count << endl;
}