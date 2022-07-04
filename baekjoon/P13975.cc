#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;

/**
 * @see [파일 합치기 3](https://www.acmicpc.net/problem/13975)
 */
int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        priority_queue<ll, vector<ll>, greater<ll> > q;
        for (int i = 0; i < K; ++i) {
            int num;
            cin >> num;
            q.push(num);
        }

        ll sum = 0;
        while (q.size() > 1) {
            ll first = q.top();
            q.pop();
            ll second = q.top();
            q.pop();
            q.push(first + second);
            sum += first + second;
        }

        cout << sum << endl;
    }

    return 0;
}