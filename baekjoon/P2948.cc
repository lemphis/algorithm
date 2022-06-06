#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [2009년](https://www.acmicpc.net/problem/2948)
 */
int main() {
    fastio;
    int D, M;
    cin >> D >> M;

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* day_of_week[] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    int count = 0;
    for (int i = 0; i < M - 1; ++i) {
        count += days[i];
    }
    count += D;

    cout << day_of_week[count % 7];

    return 0;
}