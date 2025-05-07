#include <iostream>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    set<string> colors;
    for (int i = 0; i < 4; ++i) {
        string color;
        cin >> color;
        colors.insert(color);
    }

    string output;
    output.reserve(20 * 16 * 2);
    for (const string& first : colors) {
        for (const string& second : colors) {
            output += first + ' ' + second;
            output += '\n';
        }
    }

    cout << output;

    return 0;
}