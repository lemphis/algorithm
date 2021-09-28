#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct Position {
    int x;
    int y;
} Position;

bool compare(Position a, Position b);

/**
 * @see [좌표 정렬하기](https://www.acmicpc.net/problem/11650)
 */
int main() {
    int N;
    scanf("%d", &N);
    Position positions[N];
    for (int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        positions[i] = {x, y};
    }
    sort(positions, positions + N, compare);
    for (int i = 0; i < N; ++i) {
        printf("%d %d\n", positions[i].x, positions[i].y);
    }
    return 0;
}

bool compare(Position a, Position b) { 
    return a.x == b.x ? a.y < b.y : a.x < b.x; 
}