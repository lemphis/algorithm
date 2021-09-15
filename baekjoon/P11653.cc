#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [소인수분해](https://www.acmicpc.net/problem/11653)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    if (N == 1) return 0;

    int i = 2;
    while (N != 1) {
        if (N % i == 0) {
            N /= i;
            cout << i << endl;
        } else {
            i++;
        }
    }
}