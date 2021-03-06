#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 100001

int bfs(int n, int k);

bool visit[MAX] = {0};

/**
 * @see [숨바꼭질](https://www.acmicpc.net/problem/1697)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
}

int bfs(int n, int k) {
    queue<int> q;
    visit[n] = 1;
    q.push(n);
    int count = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int now = q.front();
            q.pop();
            if (now == k) {
                return count;
            }
            if (now - 1 >= 0 && !visit[now - 1]) {
                visit[now - 1] = 1;
                q.push(now - 1);
            }
            if (now + 1 < MAX && !visit[now + 1]) {
                visit[now + 1] = 1;
                q.push(now + 1);
            }
            if (now * 2 < MAX && !visit[now * 2]) {
                visit[now * 2] = 1;
                q.push(now * 2);
            }
        }
        count++;
    }
    return count;
}