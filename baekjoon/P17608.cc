#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [막대기](https://www.acmicpc.net/problem/17608)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int height[N];
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }

    int count = 1;
    int temp = height[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        if (temp < height[i]) {
            count++;
            temp = height[i];
        }
    }

    cout << count << endl;

    return 0;
}