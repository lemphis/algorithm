#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    string num;
    cin >> num;
    int idx = 0;
    int temp = 0;
    while (idx < num.length()) {
        string s = to_string(++temp);
        for (int i = 0; i < s.length(); ++i) {
            if (num[idx] == s[i]) {
                ++idx;
            }
        }
    }

    cout << temp;

    return 0;
}
