#include <iostream>

using std::cin;
using std::cout;
using std::ios;

void solve(int* arr, int page);
void calc(int* arr, int n, int unit);

/**
 * @see [책 페이지](https://www.acmicpc.net/problem/1019)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    int arr[10] = {0};

    cin >> N;

    solve(arr, N);

    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ' ';
    }
}

void solve(int* arr, int page) {
    int start = 1;
    int end = page;
    int unit = 1;

    while (start <= end) {
        while (start % 10 != 0 && start <= end) {
            calc(arr, start, unit);
            start++;
        }
        if (start > end) break;
        while (end % 10 != 9 && start <= end) {
            calc(arr, end, unit);
            end--;
        }
        start /= 10;
        end /= 10;
        for (int i = 0; i < 10; ++i) {
            arr[i] += (end - start + 1) * unit;
        }
        unit *= 10;
    }
}

void calc(int* arr, int num, int unit) {
    while (num > 0) {
        arr[num % 10] += unit;
        num /= 10;
    }
}