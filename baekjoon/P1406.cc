#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>

#define endl '\n'

using std::cin;
using std::cout;
using std::getline;
using std::ios;
using std::list;
using std::string;

/**
 * @see [에디터](https://www.acmicpc.net/problem/1406)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    char str[100001];
    cin >> str;
    int len = strlen(str);
    list<char> chars;
    for (int i = 0; i < len; ++i) {
        chars.push_back(str[i]);
    }
    int command_count;
    cin >> command_count;
    string command;
    cin.ignore();
    while (command_count--) {
        string temp;
        getline(cin, temp);
        command += temp;
    }
    command.erase(remove(command.begin(), command.end(), ' '), command.end());
    list<char>::iterator iter = chars.end();
    int command_len = command.size();
    for (int i = 0; i < command_len; ++i) {
        if (command[i] == 'L') {
            if (iter == chars.begin()) {
                continue;
            }
            iter--;
        } else if (command[i] == 'D') {
            if (iter == chars.end()) {
                continue;
            }
            iter++;
        } else if (command[i] == 'B') {
            if (iter == chars.begin()) {
                continue;
            }
            iter--;
            iter = chars.erase(iter);
        } else if (command[i] == 'P') {
            chars.insert(iter, command[++i]);
        }
    }
    for (iter = chars.begin(); iter != chars.end(); ++iter) {
        cout << *iter;
    }
    cout << endl;
}
