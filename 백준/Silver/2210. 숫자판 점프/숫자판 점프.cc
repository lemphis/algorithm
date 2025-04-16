#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<int>>;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(const vvi& board, int r, int c, int depth, int nums[],
         unordered_set<string>& set);
inline bool is_inside(int next_r, int next_c);

int main() {
    fastio;

    vvi board(5, vector<int>(5));
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            cin >> board[r][c];
        }
    }

    unordered_set<string> set;
    int nums[6];
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            nums[0] = board[r][c];
            dfs(board, r, c, 0, nums, set);
        }
    }

    cout << set.size();

    return 0;
}

void dfs(const vvi& board, int r, int c, int depth, int nums[],
         unordered_set<string>& set) {
    if (depth > 5) {
        ostringstream oss;
        for (int i = 0; i < 6; ++i) {
            oss << nums[i];
        }
        set.insert(oss.str());

        return;
    }

    for (int i = 0; i < 4; ++i) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if (is_inside(next_r, next_c)) {
            if (depth < 5) {
                nums[depth + 1] = board[next_r][next_c];
            }
            dfs(board, next_r, next_c, depth + 1, nums, set);
        }
    }
}

inline bool is_inside(int next_r, int next_c) {
    return next_r >= 0 && next_r < 5 && next_c >= 0 && next_c < 5;
}