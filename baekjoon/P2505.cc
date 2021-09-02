#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

using std::cin;
using std::cout;
using std::find;
using std::ios;
using std::is_sorted;
using std::reverse;
using std::vector;

void print(int times, int* front, int* back);

/**
 * @see [두 번 뒤집기](https://www.acmicpc.net/problem/2505)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, cnt = 0, times = 0;
    int front[2] = {0}, back[2] = {0};
    cin >> n;
    vector<int> nums(n + 1);
    vector<int>::iterator p_find;
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    vector<int> temp = nums;
    while (cnt < 2) {
        for (int i = 1; i <= n; ++i) {
            if (i != temp[i]) {
                p_find = find(temp.begin() + 1, temp.end(), i);
                reverse(temp.begin() + i, p_find + 1);
                front[cnt] = i;
                back[cnt] = p_find - temp.begin();
                times++;
                break;
            }
        }
        cnt++;
    }
    if (!is_sorted(temp.begin() + 1, temp.end())) {
        temp = nums;
        cnt = 0;
        times = 0;
        while (cnt < 2) {
            for (int i = n; i > 0; --i) {
                if (i != temp[i]) {
                    p_find = find(temp.begin() + 1, temp.end(), i);
                    reverse(p_find, temp.begin() + i + 1);
                    front[cnt] = (temp.begin() + i) - p_find;
                    back[cnt] = i;
                    times++;
                    break;
                }
            }
            cnt++;
        }
    }
    print(times, front, back);
}

void print(int times, int* front, int* back) {
    if (times == 0) {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
    } else if (times == 1) {
        cout << front[0] << ' ' << back[0] << endl;
        cout << 1 << " " << 1 << endl;
    } else {
        cout << front[0] << ' ' << back[0] << endl;
        cout << front[1] << ' ' << back[1] << endl;
    }
}