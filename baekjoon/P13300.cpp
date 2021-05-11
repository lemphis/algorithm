#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

/**
 * @see [방 배정](https://www.acmicpc.net/problem/13300)
 */
int main() {
    int grades[2][6] = { 0 };
    int studentNum, max, gender, grade;
    int minRoomCount = 0;

    cin >> studentNum >> max;
    for (int i = 0; i < studentNum; ++i) {
        cin >> gender >> grade;
        grades[gender][grade - 1]++;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            minRoomCount += ceil(double(grades[i][j]) / double(max));
        }
    }

    cout << minRoomCount;
}