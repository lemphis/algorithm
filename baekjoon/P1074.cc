#include <cmath>
#include <cstdio>

using namespace std;

void recursive(int n, int now_r, int now_c, int r, int c, int& count);
int answer;

/**
 * @see [Z](https://www.acmicpc.net/problem/1074)
 */
int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    int count = 0;
    recursive(N, 0, 0, r, c, count);
    printf("%d\n", answer);
    return 0;
}

void recursive(int n, int now_r, int now_c, int r, int c, int& count) {
    if (now_r == r && now_c == c) {
        answer = count;
        return;
    }
    if (n == 0) {
        count++;
    } else {
        int power = pow(2, n - 1);
        if (r >= now_r && r < now_r + (power << 1) && c >= now_c && now_c < now_c + (power << 1)) {
            recursive(n - 1, now_r + 0, now_c + 0, r, c, count);
            recursive(n - 1, now_r + 0, now_c + power, r, c, count);
            recursive(n - 1, now_r + power, now_c + 0, r, c, count);
            recursive(n - 1, now_r + power, now_c + power, r, c, count);
        } else {
            count += ((power << 1) * (power << 1));
        }
    }
}