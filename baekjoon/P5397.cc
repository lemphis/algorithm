#include <cstring>
#include <iostream>
#include <list>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::list;

/**
 * @see [키로거](https://www.acmicpc.net/problem/5397)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        char inputs[1000001] = {0};
        cin >> inputs;
        int len = strlen(inputs);
        list<char> password;
        list<char>::iterator iter = password.end();
        for (int i = 0; i < len; ++i) {
            switch (inputs[i]) {
                case '<':
                    if (iter == password.begin()) {
                        continue;
                    }
                    iter--;
                    break;
                case '>':
                    if (iter == password.end()) {
                        continue;
                    }
                    iter++;
                    break;
                case '-':
                    if (iter == password.begin()) {
                        continue;
                    }
                    iter = password.erase(--iter);
                    break;
                default:
                    password.insert(iter, inputs[i]);
            }
        }
        for (iter = password.begin(); iter != password.end(); ++iter) {
            cout << *iter;
        }
        cout << endl;
    }
}