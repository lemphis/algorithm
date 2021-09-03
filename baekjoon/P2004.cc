#include <algorithm>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::min;

int find_two(int num);
int find_five(int num);

/**
 * @see [조합 0의 개수](https://www.acmicpc.net/problem/2004)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m, two, five;
    cin >> n >> m;
    two = find_two(n) - (find_two(n - m) + find_two(m));
    five = find_five(n) - (find_five(n - m) + find_five(m));
    cout << min(two, five) << endl;
}

int find_two(int num) {
    int result = 0;
    long count = 2;
    while (num >= count) {
        result += num / count;
        count *= 2;
    }
    return result;
}

int find_five(int num) {
    int result = 0;
    long count = 5;
    while (num >= count) {
        result += num / count;
        count *= 5;
    }
    return result;
}