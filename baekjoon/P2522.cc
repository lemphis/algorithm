#include <cstdio>

using namespace std;

/**
 * @see [별 찍기 - 20](https://www.acmicpc.net/problem/10995)
 */
int main() {
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            printf(r & 1 ? " *" : "* ");
        }
        puts("");
    }
    return 0;
}
