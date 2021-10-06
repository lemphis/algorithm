#include <cstdio>

using namespace std;

/**
 * @see [돌 게임](https://www.acmicpc.net/problem/9655)
 */
int main() {
    int N;
    scanf("%d", &N);
    puts(N & 1 ? "SK" : "CY");
    return 0;
}