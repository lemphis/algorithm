#include <cctype>
#include <iostream>
#include <unordered_map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    string line;
    while (getline(cin, line)) {
        char consonant[] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g',
                            'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
        char vowel[] = {'a', 'i', 'y', 'e', 'o', 'u'};

        unordered_map<char, char> map;
        for (int i = 0; i < 20; ++i) {
            map.insert({consonant[i], consonant[(i + 20 - 10) % 20]});
            map.insert({toupper(consonant[i]),
                        toupper(consonant[(i + 20 - 10) % 20])});
        }
        for (int i = 0; i < 6; ++i) {
            map.insert({vowel[i], vowel[(i + 6 - 3) % 6]});
            map.insert({toupper(vowel[i]), toupper(vowel[(i + 6 - 3) % 6])});
        }

        string ans;
        for (char c : line) {
            if (isalpha(c)) {
                ans += map[c];
            } else {
                ans += c;
            }
        }

        cout << ans << endl;
    }

    return 0;
}