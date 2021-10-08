#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * @see [수 묶기](https://www.acmicpc.net/problem/1744)
 */
int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    int sum = 0;
    int idx = 0;
    while (idx < N - 1 && arr[idx + 1] <= 0) {
        sum += (arr[idx] * arr[idx + 1]);
        idx += 2;
    }
    while (idx < N && arr[idx] < 1) {
        sum += arr[idx];
        idx++;
    }
    if ((N - idx) & 1) {
        sum += arr[idx];
        idx++;
    }
    while (idx < N - 1 && arr[idx] == 1) {
        sum += (arr[idx] + arr[idx + 1]);
        idx += 2;
    }
    while (idx < N - 1) {
        sum += (arr[idx] * arr[idx + 1]);
        idx += 2;
    }
    printf("%d\n", sum);
    return 0;
}