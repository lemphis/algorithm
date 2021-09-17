#include <iostream>
#include <queue>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::queue;

/**
 * @see [카드2](https://www.acmicpc.net/problem/2164)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    queue<int> cards;
    for (int i = 1; i <= N; ++i) {
        cards.push(i);
    }
    while (cards.size() != 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
    cout << cards.front() << endl;
}