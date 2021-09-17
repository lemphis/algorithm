#include <deque>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::deque;
using std::ios;

/**
 * @see [회전하는 큐](https://www.acmicpc.net/problem/1021)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int targets[M];
    for (int i = 0; i < M; ++i) {
        cin >> targets[i];
    }
    deque<int> items;
    for (int i = 1; i <= N; ++i) {
        items.push_back(i);
    }
    
}