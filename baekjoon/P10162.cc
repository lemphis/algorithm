#include <cstdio>

using namespace std;

/**
 * @see [전자레인지](https://www.acmicpc.net/problem/10162)
 */
int main() {
    int T;
    scanf("%d", &T);
    int buttons[3] = {300, 60, 10};
    if (T % 10 != 0) {
        printf("%d\n", -1);
        return 0;
    }
    int counts[3] = {0};
    for (int i = 0; i < 3; ++i) {
        counts[i] = (T / buttons[i]);
        T %= buttons[i];
    }
    for (int i = 0; i < 3; ++i) {
        printf("%d ", counts[i]);
    }
    return 0;
}