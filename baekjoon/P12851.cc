#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 100001

pair<int, int> bfs(int n, int k);

bool visit[MAX] = {0};

/**
 * @see [숨바꼭질 2](https://www.acmicpc.net/problem/12851)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    pair<int, int> answer = bfs(N, K);
    cout << answer.first << endl;
    cout << answer.second << endl;
}

pair<int, int> bfs(int n, int k) {
    queue<pair<int, int> > q;
    q.push({n, 0});
    visit[n] = 1;
    int count = 0;
    int kind = 0;

    while (!q.empty()) {
        pair<int, int> item = q.front();
        int now = item.first;
        int time = item.second;
        q.pop();
        visit[now] = 1;
        if (count && count == time && now == k) {
            kind++;
        }
        if (!count && now == k) {
            count = time;
            kind++;
        }
        if (count && count < time) {
            break;
        }
        if (now - 1 >= 0 && !visit[now - 1]) {
            q.push({now - 1, time + 1});
        }
        if (now + 1 < MAX && !visit[now + 1]) {
            q.push({now + 1, time + 1});
        }
        if (now * 2 < MAX && !visit[now * 2]) {
            q.push({now * 2, time + 1});
        }
    }

    return {count, kind};
}
