#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void compare_and_increment(char, int&, int&);

int main() {
    fastio;
    string S;
    cin >> S;

    int input_length = S.length();
    int zero_count = 0;
    int one_count = 0;
    char current_char = S[0];
    compare_and_increment(current_char, zero_count, one_count);
    for (int i = 0; i < input_length; ++i) {
        if (S[i] != current_char) {
            current_char = S[i];
            compare_and_increment(S[i], zero_count, one_count);
        }
    }

    cout << min(zero_count, one_count);

    return 0;
}

inline void compare_and_increment(char target, int& zero_count, int& one_count) {
    if (target == '0')
        zero_count++;
    else
        one_count++;
}