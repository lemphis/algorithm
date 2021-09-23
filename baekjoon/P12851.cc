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
    cout << answer.first << endl << answer.second << endl;
}