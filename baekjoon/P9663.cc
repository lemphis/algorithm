#include <cstdio>
#include <cstdlib>

using namespace std;

void n_queen(int n, int row, int arr[], int& count);
bool promising(int row, int arr[]);

/**
 * @see [N-Queen](https://www.acmicpc.net/problem/9663)
 */
int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    int count = 0;
    n_queen(N, 0, arr, count);
    printf("%d\n", count);
    return 0;
}

void n_queen(int n, int row, int arr[], int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 1; col <= n; ++col) {
        arr[row] = col;
        if (promising(row, arr)) {
            n_queen(n, row + 1, arr, count);
        }
    }
}

bool promising(int row, int arr[]) {
    for (int i = 0; i < row; ++i) {
        if (arr[row] == arr[i] || row - i == abs(arr[row] - arr[i])) {
            return false;
        }
    }
    return true;
}