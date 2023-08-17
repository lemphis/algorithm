#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Pos {
    int r;
    int c;
    int count;
} Pos;

int solution(vector<vector<int>> maps) {
    int row_count = maps.size();
    int col_count = maps[0].size();
    int count = -1;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    queue<Pos> q;
    q.push({0, 0, 1});
    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int q_count = q.front().count;
        if (r == row_count - 1 && c == col_count - 1) {
            count = q_count;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_r = dr[i] + r;
            int next_c = dc[i] + c;
            if (next_r >= 0 && next_r < row_count && next_c >= 0 && next_c < col_count && maps[next_r][next_c] == 1) {
                q.push({next_r, next_c, q_count + 1});
                maps[next_r][next_c] = 0;
            }
        }
    }

    return count;
}