#include <iostream>

using std::cin;
using std::cout;
using std::ios;
using std::string;

/**
 * @see [음계](https://www.acmicpc.net/problem/2920)
 */
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int arr[8];
    int count = 0;
    string answer;
    for (int i = 0; i < 8; ++i) cin >> arr[i];
    for (int i = 0; i < 8; ++i) {
        if (i + 1 == arr[i])
            count++;
        else if (i + 1 == arr[7 - i])
            count--;
    }

    if (count == 8)
        answer = "ascending";
    else if (count == -8)
        answer = "descending";
    else
        answer = "mixed";

    cout << answer << '\n';
}