#include <iostream>

#define endl '\n'
#define MAX_SIZE (123456 + 1) * 2

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [베르트랑 공준](https://www.acmicpc.net/problem/4948)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    bool arr[MAX_SIZE];
    while (1) {
        for (int i = 0; i < sizeof(arr); ++i) {
            arr[i] = 1;
        }
        arr[1] = 0;
        cin >> n;
        if (n == 0) break;
        for (int i = 2; i <= n * 2; ++i) {
            int idx = 2;
            while (i * idx <= MAX_SIZE) {
                if (arr[i * idx]) arr[i * idx] = 0;
                idx++;
            }
        }
        int cnt = 0;
        for (int i = n + 1; i <= n * 2; ++i) {
            if (arr[i]) cnt++;
        }
        cout << cnt << endl;
    }
}