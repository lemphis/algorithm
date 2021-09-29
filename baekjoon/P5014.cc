#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int bfs(bool visit[], int f, int s, int g, int u, int d);

/**
 * @see [스타트링크](https://www.acmicpc.net/problem/5014)
 */
int main() {
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    bool visit[F + 1];
    memset(visit, 0, sizeof(visit));
    int min_times = bfs(visit, F, S, G, U, D);
    if (min_times == -1) {
        puts("use the stairs");
    } else {
        printf("%d\n", min_times);
    }

    return 0;
}

int bfs(bool visit[], int f, int s, int g, int u, int d) {
    queue<int> q;
    int count = 0;
    q.push(s);
    visit[s] = 1;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int now = q.front();
            q.pop();
            if (now == g) {
                return count;
            }
            if (now + u <= f && !visit[now + u]) {
                q.push(now + u);
                visit[now + u] = 1;
            }
            if (now - d > 0 && !visit[now - d]) {
                q.push(now - d);
                visit[now - d] = 1;
            }
        }
        count++;
    }

    return -1;
}