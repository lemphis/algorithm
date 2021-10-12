#include <cmath>
#include <cstdio>

using namespace std;

void hanoi(int n, int src, int temp, int dest);

/**
 * @see [하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729)
 */
int main() {
    int N;
    scanf("%d", &N);
    printf("%.0f\n", pow(2, N) - 1);
    hanoi(N, 1, 2, 3);
    return 0;
}

void hanoi(int n, int src, int temp, int dest) {
    if (n == 1) {
        printf("%d %d\n", src, dest);
    } else {
        hanoi(n - 1, src, dest, temp);
        printf("%d %d\n", src, dest);
        hanoi(n - 1, temp, src, dest);
    }
}