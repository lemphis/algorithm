#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [역원소 정렬](https://www.acmicpc.net/problem/5648)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    long long items[N];
    for (int i = 0; i < N; ++i) {
        string item;
        cin >> item;
        reverse(item.begin(), item.end());
        items[i] = stoll(item);
    }

    sort(items, items + N);

    for (int i = 0; i < N; ++i) {
        cout << items[i] << endl;
    }

    return 0;
}