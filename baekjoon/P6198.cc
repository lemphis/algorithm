#include <iostream>
#include <stack>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::stack;

/**
 * @see [옥상 정원 꾸미기](https://www.acmicpc.net/problem/6198)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int height[N];
    long long count = 0;
    stack<int> buildings;
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }
    int idx = 0;
    while (N > idx) {
        while (!buildings.empty() && buildings.top() <= height[idx]) {
            buildings.pop();
        }
        count += (long long)buildings.size();
        cout << count << endl;
        buildings.push(height[idx]);
        idx++;
    }
    cout << count << endl;
}