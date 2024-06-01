#include <iostream>
#include <regex>
#include <string>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    regex pattern("(100+1+|01)+");
    while (n--) {
        string s;
        cin >> s;
        if (regex_match(s, pattern)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}