#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::max_element;

/**
 * @see [방 번호](https://www.acmicpc.net/problem/1475)
 */
int main() {
    int numbers[10] = {0};
    int room_num;
    int total = 0;
    cin >> room_num;
    if (room_num < 10) {
        cout << 1;
        return 0;
    }
    while (room_num > 0) {
        numbers[room_num % 10]++;
        total++;
        room_num /= 10;
    }
    int recycle = ceil((double(numbers[6]) + double(numbers[9])) / 2);
    numbers[6] = numbers[9] = 0;
    int other = *max_element(&numbers[0], &numbers[9]);
    cout << max(recycle, other);
}