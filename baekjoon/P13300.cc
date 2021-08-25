#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [방 배정](https://www.acmicpc.net/problem/13300)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int grades[2][6] = {0};
    int student_num, max, gender, grade;
    int min_room_count = 0;

    cin >> student_num >> max;
    for (int i = 0; i < student_num; ++i) {
        cin >> gender >> grade;
        grades[gender][grade - 1]++;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            min_room_count += ceil(double(grades[i][j]) / double(max));
        }
    }

    cout << min_room_count;
}