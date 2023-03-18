#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

struct compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};

int main() {
    fastio;
    int N;
    cin >> N;
    priority_queue<pii, vector<pii>, compare> pq;
    priority_queue<int, vector<int>, greater<int>> ans_q;
    for (int i = 0; i < N; ++i) {
        pii item;
        cin >> item.first >> item.second;
        pq.push(item);
    }

    int time = 1;
    while (!pq.empty()) {
        pii question = pq.top();
        pq.pop();
        if (question.first >= time) {
            ++time;
            ans_q.push(question.second);
        } else {
            if (question.second > ans_q.top()) {
                ans_q.pop();
                ans_q.push(question.second);
            }
        }
    }

    long ans = 0;
    while (!ans_q.empty()) {
        ans += ans_q.top();
        ans_q.pop();
    }

    cout << ans;

    return 0;
}