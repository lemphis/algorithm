#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::max;
using std::max_element;

int main() {
    int numbers[10] = { 0 };
    int roomNum;
    int total = 0;
    cin >> roomNum;
    if (roomNum < 10) {
        cout << 1;
        return 0;
    }
    while (roomNum > 0) {
        numbers[roomNum % 10]++;
        total++;
        roomNum /= 10;
    }
    int recycle = ceil((double(numbers[6]) + double(numbers[9])) / 2);
    numbers[6] = numbers[9] = 0;
    int other = *max_element(&numbers[0], &numbers[9]);
    cout << max(recycle, other);
}