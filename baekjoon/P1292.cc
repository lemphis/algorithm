#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [쉽게 푸는 문제](https://www.acmicpc.net/problem/1292)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int A, B, i = 1, idx = 1;
    cin >> A >> B;
    int sums[1001] = {0};
    while (i <= 1000) {
        for (int j = 0; j < idx; ++j) {
            if (i > 1000) break;
            sums[i] = idx;
            i++;
        }
        idx++;
    }
    int answer = 0;
    for (i = A; i <= B; ++i) {
        answer += sums[i];
    }
    cout << answer << endl;
}