#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [카드1](https://www.acmicpc.net/problem/2161)
 */
int main() {
    fastio;
    int N;
    cin >> N;

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }

    return 0;
}