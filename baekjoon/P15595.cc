#include <cmath>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [정답 비율 계산하기](https://www.acmicpc.net/problem/15595)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, num, result, memory, performance, language, length, answer = 0, ac = 0, wa = 0;
    char id[20];
    cin >> n;
    while (n--) {
        cin >> num >> id >> result >> memory >> performance >> language >> length;
        if (id == "megalusion") continue;
    }
}
