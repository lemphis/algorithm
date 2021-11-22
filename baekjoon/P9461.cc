#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 101

/**
 * @see [파도반 수열](https://www.acmicpc.net/problem/9461)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    long long memo[MAX] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    for (int i = 11; i < MAX; ++i) {
        memo[i] = memo[i - 1] + memo[i - 5];
    }
    while (T--) {
        int N;
        cin >> N;
        cout << memo[N] << endl;
    }

    return 0;
}