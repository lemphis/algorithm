#include <iostream>
#include <stack>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::stack;

/**
 * @see [제로](https://www.acmicpc.net/problem/10773)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int K;
    cin >> K;
    stack<int> nums;
    while (K--) {
        int num;
        cin >> num;
        if (num == 0) {
            nums.pop();
        } else {
            nums.push(num);
        }
    }
    int sum = 0;
    while (!nums.empty()) {
        sum += nums.top();
        nums.pop();
    }
    cout << sum << endl;
}
