#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 100001

int bfs(int n, int k);

int parent[MAX] = {0};

/**
 * @see [숨바꼭질 4](https://www.acmicpc.net/problem/13913)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int count = bfs(N, K);
    cout << count << endl;
    int footprint[count + 1];
    footprint[0] = N;
    footprint[count] = K;
    for (int i = count - 1; i > 0; --i) {
        footprint[i] = parent[K];
        K = parent[K];
    }
    for (int i = 0; i <= count; ++i) {
        cout << footprint[i] << ' ';
    }
    cout << endl;
    return 0;
}

int bfs(int n, int k) {
    queue<int> q;
    parent[n] = n;
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
            if (now - 1 >= 0 && !parent[now - 1]) {
                parent[now - 1] = now;
                q.push(now - 1);
            }
            if (now + 1 < MAX && !parent[now + 1]) {
                parent[now + 1] = now;
                q.push(now + 1);
            }
            if (now * 2 < MAX && !parent[now * 2]) {
                parent[now * 2] = now;
                q.push(now * 2);
            }
        }
        count++;
    }

    return count;
}