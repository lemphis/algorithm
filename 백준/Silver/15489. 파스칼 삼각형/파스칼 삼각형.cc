#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int R, C, W;
    cin >> R >> C >> W;
    --R, --C;

    int pascal_triangle[30][30];
    memset(pascal_triangle, 0, sizeof(pascal_triangle));
    pascal_triangle[0][0] = 1;
    for (int r = 1; r < 30; ++r) {
        for (int c = 0; c <= r; ++c) {
            if (c > 0) {
                pascal_triangle[r][c] += pascal_triangle[r - 1][c - 1];
            }
            if (r > c) {
                pascal_triangle[r][c] += pascal_triangle[r - 1][c];
            }
        }
    }

    int sum = 0;
    for (int r = R; r < R + W; ++r) {
        for (int c = C; c < r - R + C + 1; ++c) {
            sum += pascal_triangle[r][c];
        }
    }

    cout << sum;

    return 0;
}