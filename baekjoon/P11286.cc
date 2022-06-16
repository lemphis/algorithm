#include <cmath>
#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

typedef struct Compare {
    bool operator()(int& a, int& b) {
        int temp_a = abs(a);
        int temp_b = abs(b);
        return temp_a == temp_b ? a > b : temp_a > temp_b;
    }
} Compare;

/**
 * @see [절댓값 힙](https://www.acmicpc.net/problem/11286)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    priority_queue<int, vector<int>, Compare> queue;
    while (N--) {
        int num;
        cin >> num;
        if (num == 0) {
            if (queue.empty()) {
                cout << 0 << endl;
            } else {
                cout << queue.top() << endl;
                queue.pop();
            }
        } else {
            queue.push(num);
        }
    }

    return 0;
}