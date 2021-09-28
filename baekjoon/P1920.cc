#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * @see [수 찾기](https://www.acmicpc.net/problem/1920)
 */
int main() {
    int N, M;
    scanf("%d", &N);
    int A[100000];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    sort(A, A + N);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int target;
        scanf("%d", &target);
        if (target < A[0] || target > A[N - 1]) {
            printf("%d\n", 0);
            continue;
        }
        bool exists = false;
        int start = 0;
        int end = N - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > A[mid]) {
                start = mid + 1;
            } else if (target < A[mid]) {
                end = mid - 1;
            } else {
                exists = true;
                break;
            }
        }
        printf("%d\n", exists ? 1 : 0);
    }
    return 0;
}