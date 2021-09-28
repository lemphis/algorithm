#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

/**
 * @see [직각삼각형](https://www.acmicpc.net/problem/4153)
 */
int main() {
    while (1) {
        int lengths[3];
        scanf("%d %d %d", &lengths[0], &lengths[1], &lengths[2]);
        if (!lengths[0] && !lengths[1] && !lengths[2]) {
            break;
        }
        sort(lengths, lengths + 3);
        puts(pow(lengths[0], 2) + pow(lengths[1], 2) == pow(lengths[2], 2) ? "right" : "wrong");
    }
    return 0;
}