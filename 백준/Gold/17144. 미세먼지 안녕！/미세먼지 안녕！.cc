#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<int>>;
using pii = pair<int, int>;

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

void spread_dust(vvi& house, pii& air_purifier_top, pii& air_purifier_bottom);
inline bool is_inside(int row, int col, int r, int c);
void clear_air(vvi& house, pii& air_purifier_top, pii& air_purifier_bottom);
void clear_top(vvi& house, pii& air_purifier_top);
void clear_bottom(vvi& house, pii& air_purifier_bottom);

int main() {
    fastio;

    int R, C, T;
    cin >> R >> C >> T;
    vvi house(R, vector<int>(C));

    pii air_purifier_top = {-1, -1};
    pii air_purifier_bottom = {-1, -1};
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> house[r][c];
            if (house[r][c] == -1) {
                if (air_purifier_top.first == -1 &&
                    air_purifier_top.second == -1) {
                    air_purifier_top = {r, c};
                } else {
                    air_purifier_bottom = {r, c};
                }
            }
        }
    }

    while (T--) {
        spread_dust(house, air_purifier_top, air_purifier_bottom);
        clear_air(house, air_purifier_top, air_purifier_bottom);
    }

    int dust_count = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (house[r][c] > 0) {
                dust_count += house[r][c];
            }
        }
    }

    cout << dust_count;

    return 0;
}

void spread_dust(vvi& house, pii& air_purifier_top, pii& air_purifier_bottom) {
    int row = house.size();
    int col = house[0].size();

    vvi new_house(row, vector<int>(col, 0));
    new_house[air_purifier_top.first][air_purifier_top.second] = -1;
    new_house[air_purifier_bottom.first][air_purifier_bottom.second] = -1;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (house[r][c] > 0) {
                int spread_dust_size = house[r][c] / 5;
                int spread_count = 0;
                for (int i = 0; i < 4; ++i) {
                    int next_r = r + dr[i];
                    int next_c = c + dc[i];
                    if (is_inside(row, col, next_r, next_c) &&
                        house[next_r][next_c] > -1) {
                        new_house[next_r][next_c] += spread_dust_size;
                        ++spread_count;
                    }
                }
                new_house[r][c] +=
                    house[r][c] - (spread_dust_size * spread_count);
            }
        }
    }

    house.swap(new_house);
}

inline bool is_inside(int row, int col, int r, int c) {
    return r >= 0 && r < row && c >= 0 && c < col;
}

void clear_air(vvi& house, pii& air_purifier_top, pii& air_purifier_bottom) {
    clear_top(house, air_purifier_top);
    clear_bottom(house, air_purifier_bottom);
}

void clear_top(vvi& house, pii& air_purifier_top) {
    int row = air_purifier_top.first + 1;
    int col = house[0].size();
    for (int r = row - 2; r > 0; --r) {
        house[r][0] = house[r - 1][0];
    }
    for (int c = 0; c < col - 1; ++c) {
        house[0][c] = house[0][c + 1];
    }
    for (int r = 0; r < row - 1; ++r) {
        house[r][col - 1] = house[r + 1][col - 1];
    }
    for (int c = col - 1; c > 1; --c) {
        house[row - 1][c] = house[row - 1][c - 1];
    }
    house[row - 1][1] = 0;
}

void clear_bottom(vvi& house, pii& air_purifier_bottom) {
    int row_base = air_purifier_bottom.first;
    int row = house.size();
    int col = house[0].size();
    for (int r = row_base + 1; r < row - 1; ++r) {
        house[r][0] = house[r + 1][0];
    }
    for (int c = 0; c < col - 1; ++c) {
        house[row - 1][c] = house[row - 1][c + 1];
    }
    for (int r = row - 1; r > row_base; --r) {
        house[r][col - 1] = house[r - 1][col - 1];
    }
    for (int c = col - 1; c > 1; --c) {
        house[row_base][c] = house[row_base][c - 1];
    }
    house[row_base][1] = 0;
}