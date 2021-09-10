#include <cstring>
#include <deque>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::deque;
using std::ios;
using std::string;

/**
 * @see [폭발 문자열](https://www.acmicpc.net/problem/9935)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    char target[1000001], bomb[37];
    cin >> target >> bomb;
    int t_len = strlen(target);
    int b_len = strlen(bomb);
    deque<char> dq;
    for (int i = 0; i < t_len; ++i) {
        dq.push_back(target[i]);
        int size = dq.size();
        if (size >= b_len) {
            bool is_same = true;
            for (int idx = 0; idx < b_len; ++idx) {
                if (dq[size - b_len + idx] != bomb[idx]) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) {
                for (int idx = 0; idx < b_len; ++idx) {
                    dq.pop_back();
                }
            }
        }
    }
    string answer;
    for (int i = 0; i < dq.size(); ++i) {
        answer += dq[i];
    }

    if (answer.size() == 0)
        cout << "FRULA" << endl;
    else
        cout << answer << endl;
}