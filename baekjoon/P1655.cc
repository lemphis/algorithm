#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [가운데를 말해요](https://www.acmicpc.net/problem/1655)
 */
int main() {
    fastio;
    int N;
    cin >> N;

    priority_queue<int, vector<int> > gq;
    priority_queue<int, vector<int>, greater<int> > lq;

    int num;
    cin >> num;
    gq.push(num);
    cout << num << endl;
    for (int i = 1; i < N; ++i) {
        cin >> num;
        if (i & 1) {
            lq.push(num);
        } else {
            gq.push(num);
        }
        if (lq.top() < gq.top()) {
            int lq_tmp = lq.top();
            int gq_tmp = gq.top();
            lq.pop();
            lq.push(gq_tmp);
            gq.pop();
            gq.push(lq_tmp);
        }
        cout << gq.top() << endl;
    }

    return 0;
}