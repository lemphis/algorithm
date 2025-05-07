#include <algorithm>
#include <iostream>
#include <unordered_set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    unordered_set<string> colors;
    for (int i = 0; i < 4; ++i) {
        string color;
        cin >> color;
        colors.insert(color);
    }

    vector<string> combinations;
    for (const string& first : colors) {
        for (const string& second : colors) {
            combinations.push_back(first + ' ' + second);
        }
    }

    sort(combinations.begin(), combinations.end());

    string output;
    output.reserve(20 * 16 * 2);
    for (string& s : combinations) {
        output += s;
        output += '\n';
    }

    cout << output;

    return 0;
}