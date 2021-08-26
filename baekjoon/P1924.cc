#include <cstring>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [2007년](https://www.acmicpc.net/problem/1924)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    cin >> m >> d;
    m -= 1;
    while (m--) {
        d += days[m];
    }

    char answer[4];
    switch (d % 7) {
        case 0:
            strcpy(answer, "SUN");
            break;
        case 1:
            strcpy(answer, "MON");
            break;
        case 2:
            strcpy(answer, "TUE");
            break;
        case 3:
            strcpy(answer, "WED");
            break;
        case 4:
            strcpy(answer, "THU");
            break;
        case 5:
            strcpy(answer, "FRI");
            break;
        case 6:
            strcpy(answer, "SAT");
            break;
    }

    cout << answer << endl;
}