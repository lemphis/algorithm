#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 500001

int bfs(int n, int k);

bool visit[MAX][2] = {0};

/**
 * @see [숨바꼭질 5](https://www.acmicpc.net/problem/17071)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    cout << (N == K ? 0 : bfs(N, K)) << endl;
}

int bfs(int n, int k) {
    queue<int> q;
    visit[n][0] = 1;
    q.push(n);
    int count = 1;
    int speed = 1;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 3; ++i) {
                int next = now;
                if (i == 0) {
                    next += 1;
                } else if (i == 1) {
                    next -= 1;
                } else {
                    next *= 2;
                }
                if (next >= 0 && next < MAX && !visit[next][count % 2]) {
                    q.push(next);
                    visit[next][count % 2] = 1;
                }
            }
        }
        if (k + speed >= MAX) {
            return -1;
        }
        if (visit[k + speed][count % 2]) {
            break;
        }
        count++;
        speed += count;
    }
    return count;
}