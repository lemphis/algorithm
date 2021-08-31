#include <cstdio>

/**
 * @see [더하기 3](https://www.acmicpc.net/problem/11023)
 */
int main() {
    int n, sum = 0;
    while (~scanf("%d", &n)) sum += n;
    printf("%d", sum);
}