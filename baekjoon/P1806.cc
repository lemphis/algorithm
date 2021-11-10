#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [부분합](https://www.acmicpc.net/problem/1806)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, S;
    cin >> N >> S;
    int seq[N];
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    int min_len = 0xffffffff >> 1;
    int i = 0, j = 0;
    int sum = seq[0];
    while (i <= j && j < N) {
        if (sum >= S) {
            if (j - i + 1 < min_len) {
                min_len = j - i + 1;
            }
            sum -= seq[i++];
        } else {
            sum += seq[++j];
        }
    }

    cout << (min_len > 100000 ? 0 : min_len) << endl;
    return 0;
}