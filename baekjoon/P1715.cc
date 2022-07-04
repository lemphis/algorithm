#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [카드 정렬하기](https://www.acmicpc.net/problem/1715)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        q.push(num);
    }

    int sum = 0;
    while (q.size() > 1) {
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        q.push(first + second);
        sum += first + second;
    }

    cout << sum << endl;

    return 0;
}