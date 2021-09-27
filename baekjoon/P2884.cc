#include <cstdio>

using namespace std;

/**
 * @see [알람 시계](https://www.acmicpc.net/problem/2884)
 */
int main() {
    int H, M;
    scanf("%d %d", &H, &M);
    if (M < 45) {
        M = 60 - (45 - M);
        if (H == 0) {
            H = 23;
        } else {
            H -= 1;
        }
    } else {
        M -= 45;
    }
    printf("%d %d", H, M);
    return 0;
}