#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

pair<int, int> hilbert(int n, int m);

/**
 * @see [Philosopher’s Walk](https://www.acmicpc.net/problem/14956)
 */
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    auto [x, y] = hilbert(n, m - 1);
    printf("%d %d\n", x, y);
    return 0;
}

pair<int, int> hilbert(int n, int m) {
    if (n == 2) {
        switch (m) {
            case 0:
                return {1, 1};
            case 1:
                return {1, 2};
            case 2:
                return {2, 2};
            case 3:
                return {2, 1};
        }
    }
    int half = n >> 1;
    auto [x, y] = hilbert(half, m % (half * half));
    switch (m / (half * half)) {
        case 0:
            swap(x, y);
            break;
        case 1:
            y += half;
            break;
        case 2:
            x += half;
            y += half;
            break;
        case 3:
            int x_temp = x;
            x = half * 2 - y + 1;
            y = half - x_temp + 1;
            break;
    }
    return {x, y};
}