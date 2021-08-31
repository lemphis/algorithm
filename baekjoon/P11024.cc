#include <cstring>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::string;

/**
 * @see [더하기 4](https://www.acmicpc.net/problem/11024)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t, sum = 0;
    string s, tmp;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            tmp += s[i];
            if (s[i] == ' ' || i == len - 1) {
                sum += stoi(tmp);
                tmp = "";
            }
        }
        s = "";
        cout << sum << endl;
        sum = 0;
    }
}