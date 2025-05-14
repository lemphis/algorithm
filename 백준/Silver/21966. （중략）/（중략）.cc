#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    string S;
    cin >> N >> S;

    if (S.length() <= 25) {
        cout << S;
    } else {
        int last_idx = S.length() - 11;
        bool is_same_sentence = true;
        for (int i = 11; i < last_idx - 1; ++i) {
            if (S[i] == '.') {
                is_same_sentence = false;
                break;
            }
        }
        string ans;
        if (is_same_sentence) {
            cout << S.substr(0, 11) << "..." << S.substr(last_idx);
        } else {
            cout << S.substr(0, 9) << "......" << S.substr(S.length() - 10);
        }
    }

    return 0;
}