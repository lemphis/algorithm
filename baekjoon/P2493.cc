#include <iostream>
#include <stack>
#include <utility>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::make_pair;
using std::pair;
using std::stack;

/**
 * @see [탑](https://www.acmicpc.net/problem/2493)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int heights[N];
    stack<pair<int, int> > tower;
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
        while (!tower.empty()) {
            if (tower.top().second > heights[i]) {
                cout << tower.top().first << ' ';
                break;
            }
            tower.pop();
        }
        if (tower.empty()) {
            cout << 0 << ' ';
        }
        tower.push(make_pair(i + 1, heights[i]));
    }
}