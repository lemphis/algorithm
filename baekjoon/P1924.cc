#include <iostream>

using std::cin;
using std::cout;
using std::ios;
using std::string;

/**
 * @see [2007년](https://www.acmicpc.net/problem/1924)
 */
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    cin >> m >> d;
    m -= 1;
    while (m--) {
        d += days[m];
    }

    string answer;
    switch (d % 7) {
        case 0:
            answer = "SUN";
            break;
        case 1:
            answer = "MON";
            break;
        case 2:
            answer = "TUE";
            break;
        case 3:
            answer = "WED";
            break;
        case 4:
            answer = "THU";
            break;
        case 5:
            answer = "FRI";
            break;
        case 6:
            answer = "SAT";
            break;
    }

    cout << answer << '\n';
}