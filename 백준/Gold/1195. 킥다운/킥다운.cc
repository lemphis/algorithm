#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    string g1, g2;
    cin >> g1 >> g2;
    if (g1.length() > g2.length()) {
        g2.swap(g1);
    }
    int ans = g1.length() + g2.length();
    for (int i = 1; i < g1.length(); ++i) {
        bool is_same = true;
        for (int j = 0; j < g1.length() - i; ++j) {
            if (g1[i + j] == '2' && g2[j] == '2') {
                is_same = false;
                break;
            }
        }
        if (is_same) {
            ans = min(ans, (int)g2.length() + i);
        }
    }
    for (int i = 0; i <= g2.length() - g1.length(); ++i) {
        bool is_same = true;
        for (int j = 0; j < g1.length(); ++j) {
            if (g1[j] == '2' && g2[i + j] == '2') {
                is_same = false;
                break;
            }
        }
        if (is_same) {
            ans = min(ans, (int)g2.length());
        }
    }
    for (int i = 1; i < g1.length(); ++i) {
        bool is_same = true;
        for (int j = 0; j < i; ++j) {
            if (g1[j] == '2' && g2[g2.length() - i + j] == '2') {
                is_same = false;
                break;
            }
        }
        if (is_same) {
            ans = min(ans, (int)g2.length() + (int)g1.length() - i);
        }
    }
    cout << ans;

    return 0;
}