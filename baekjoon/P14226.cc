#include <iostream>
#include <queue>
#include <tuple>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MAX 1001

using namespace std;
using ti = tuple<int, int, int>;

bool visited[MAX][MAX] = {0};

int bfs(int S);

/**
 * @see [이모티콘](https://www.acmicpc.net/problem/14226)
 */
int main() {
    fastio;
    int S;
    cin >> S;

    cout << bfs(S) << endl;

    return 0;
}

int bfs(int S) {
    queue<ti> q;
    q.push({1, 0, 0});
    visited[1][0] = 1;

    int count = 0;
    while (!q.empty()) {
        auto [now, clip, times] = q.front();
        if (now == S) {
            count = times;
            break;
        }
        q.pop();
        if (now - 1 > 0 && !visited[now - 1][clip]) {
            q.push({now - 1, clip, times + 1});
            visited[now - 1][clip] = 1;
        }
        if (now + clip <= S && !visited[now + clip][clip]) {
            q.push({now + clip, clip, times + 1});
            visited[now + clip][clip] = 1;
        }
        if (!visited[now][now]) {
            q.push({now, now, times + 1});
            visited[now][now] = 1;
        }
    }

    return count;
}