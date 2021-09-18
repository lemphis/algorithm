#include <algorithm>
#include <deque>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::deque;
using std::find;
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
    int count = 0;
    for (int i = 0; i < M; ++i) {
        deque<int>::iterator iter = find(items.begin(), items.end(), targets[i]);
        bool condition = items.end() - iter > iter - items.begin();
        while (items.front() != targets[i]) {
            if (condition) {
                items.push_back(items.front());
                items.pop_front();
            } else {
                items.push_front(items.back());
                items.pop_back();
            }
            count++;
        }
        items.pop_front();
    }
    cout << count << endl;
}