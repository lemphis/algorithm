#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    if (a[0] != b[0] || a[N - 1] != b[N - 1]) {
        cout << "NO";
        return 0;
    }

    string temp_a = a, temp_b = b;
    sort(temp_a.begin(), temp_a.end());
    sort(temp_b.begin(), temp_b.end());
    if (temp_a != temp_b) {
        cout << "NO";
        return 0;
    }

    string ca, cb;
    for (char ch : a) {
        if (string("aeiou").find(ch) != string::npos)
            continue;
        ca += ch;
    }
    for (char ch : b) {
        if (string("aeiou").find(ch) != string::npos)
            continue;
        cb += ch;
    }
    if (ca != cb) {
        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}