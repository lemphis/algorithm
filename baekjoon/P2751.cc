#include <algorithm>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::sort;

/**
 * @see [수 정렬하기 2](https://www.acmicpc.net/problem/2751)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << endl;
    }
}