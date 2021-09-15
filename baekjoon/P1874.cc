#include <iostream>
#include <stack>
#include <vector>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::stack;
using std::vector;

/**
 * @see [스택 수열](https://www.acmicpc.net/problem/1874)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    stack<int> temp;
    vector<char> sign;
    int push_count = 0;
    for (push_count = 0; push_count < nums[0]; ++push_count) {
        temp.push(push_count + 1);
        sign.push_back('+');
    }
    temp.pop();
    sign.push_back('-');
    int idx = 1;
    while (idx < n) {
        if (nums[idx] > nums[idx - 1]) {
            if (push_count == n) {
                break;
            }
            int tmp = push_count;
            for (int i = 0; i < nums[idx] - tmp; ++i) {
                temp.push(++push_count);
                sign.push_back('+');
            }
        } else {
            if (temp.empty()) {
                break;
            }
            while (temp.top() != nums[idx]) {
                temp.pop();
                sign.push_back('-');
            }
        }
        temp.pop();
        sign.push_back('-');
        idx++;
    }
    if (idx == n) {
        for (int i = 0; i < sign.size(); ++i) {
            cout << sign[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}