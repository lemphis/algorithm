#include <cstring>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::string;
using std::to_string;

/**
 * @see [감소하는 수](https://www.acmicpc.net/problem/1038)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, temp = 11;
    long long answer = 11;
    string s;
    cin >> n;
    if (n <= 10) {
        cout << n << endl;
        return 0;
    }
    while (temp != n) {
        if (answer > 9876543210) {
            answer = -1;
            break;
        }
        s = to_string(answer);
        if (s.length() > (s[0] - '0')) {
            string add = "1";
            for (int i = 0; i < s.length() - 1; ++i) {
                add.append("0");
            }
            answer += stoi(add);
            continue;
        }
        bool is_desc = true;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] <= s[i + 1]) {
                is_desc = false;
                break;
            }
        }
        if (is_desc) temp++;
        answer++;
    }
    cout << answer << endl;
}