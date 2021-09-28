#include <cstdio>

using namespace std;

/**
 * @see [팰린드롬수](https://www.acmicpc.net/problem/1259)
 */
int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (!n) {
            break;
        }
        int arr[4] = {0};
        int idx = 0;
        while (n > 0) {
            arr[idx++] = n % 10;
            n /= 10;
        }
        bool is_palindrome = true;
        for (int i = 0; i < idx / 2; ++i) {
            if (arr[i] != arr[(idx - 1) - i]) {
                is_palindrome = false;
                break;
            }
        }
        puts(is_palindrome ? "yes" : "no");
    }
    return 0;
}
