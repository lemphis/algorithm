#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 100001

int bfs(int n, int k);

bool visit[MAX] = {0};

/**
 * @see [숨바꼭질 3](https://www.acmicpc.net/problem/13549)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
}

int bfs(int n, int k) {
    queue<pair<int, int> > q;
    visit[n] = 1;
    q.push({n, 0});

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int now = q.front().first;
            int time = q.front().second;
            q.pop();
            if (now == k) {
                return time;
            }
            if (now * 2 < MAX && !visit[now * 2]) {
                visit[now * 2] = 1;
                q.push({now * 2, time});
            }
            if (now - 1 >= 0 && !visit[now - 1]) {
                visit[now - 1] = 1;
                q.push({now - 1, time + 1});
            }
            if (now + 1 < MAX && !visit[now + 1]) {
                visit[now + 1] = 1;
                q.push({now + 1, time + 1});
            }
        }
    }

    return 0;
}