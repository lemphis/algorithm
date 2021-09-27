#include <cstdio>
#include <cstring>

using namespace std;

/**
 * @see [집합](https://www.acmicpc.net/problem/11723)
 */
int main() {
    int M;
    scanf("%d", &M);
    int set = 0;
    while (M--) {
        char command[7];
        int num;
        scanf("%s %d", command, &num);
        if (strcmp(command, "add") == 0) {
            set |= (1 << num);
        } else if (strcmp(command, "remove") == 0) {
            set &= ~(1 << num);
        } else if (strcmp(command, "check") == 0) {
            printf("%d\n", set & (1 << num) ? 1 : 0);
        } else if (strcmp(command, "toggle") == 0) {
            set ^= (1 << num);
        } else if (strcmp(command, "all") == 0) {
            set |= ~(1 << 21);
        } else if (strcmp(command, "empty") == 0) {
            set &= (1 << 21);
        }
    }
}