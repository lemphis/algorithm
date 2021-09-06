#include <algorithm>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::min;

int find_n(int num, int n);

/**
 * @see [조합 0의 개수](https://www.acmicpc.net/problem/2004)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m, two, five;
    cin >> n >> m;
    two = find_n(n, 2) - (find_n(n - m, 2) + find_n(m, 2));
    five = find_n(n, 5) - (find_n(n - m, 5) + find_n(m, 5));
    cout << min(two, five) << endl;
}

int find_n(int num, int n) {
    int result = 0;
    long count = n;
    while (num >= count) {
        result += num / count;
        count *= n;
    }
    return result;
}