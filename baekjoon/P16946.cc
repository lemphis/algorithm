#include <iostream>
#include <queue>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MAX 1'000

using namespace std;
using pii = pair<int, int>;

bool map[MAX][MAX];
int ans[MAX][MAX] = {0};
int group[MAX][MAX] = {0};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void count_blocks(int r, int c, int N, int M, int& last_group_idx);
inline bool predicate(int r, int c, int max_r, int max_c);

/**
 * @see [벽 부수고 이동하기 4](https://www.acmicpc.net/problem/16946)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        char row[M + 1];
        cin >> row;
        for (int c = 0; c < M; ++c) {
            map[r][c] = row[c] == '1';
        }
    }

    int last_group_idx = 1;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c] == 0 && group[r][c] == 0) {
                count_blocks(r, c, N, M, last_group_idx);
            }
        }
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c] == 1) {
                set<int> s;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == 0) {
                        if (s.find(group[nr][nc]) == s.end()) {
                            s.insert(group[nr][nc]);
                            ans[r][c] += ans[nr][nc];
                        }
                    }
                }
                ans[r][c] += 1;
                ans[r][c] %= 10;
            }
        }
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c] == 0) {
                ans[r][c] = 0;
            }
        }
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << ans[r][c];
        }
        cout << endl;
    }

    return 0;
}

void count_blocks(int r, int c, int N, int M, int& last_group_idx) {
    queue<pii> q;
    vector<pii> v;
    pii pos = make_pair(r, c);
    q.push(pos);
    v.push_back(pos);
    group[r][c] = last_group_idx;
    int count = 1;
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (predicate(nr, nc, N, M)) {
                group[nr][nc] = last_group_idx;
                pii next_pos = make_pair(nr, nc);
                q.push(next_pos);
                v.push_back(next_pos);
                count++;
            }
        }
    }

    int size = v.size();
    for (int i = 0; i < size; ++i) {
        auto [r, c] = v[i];
        ans[r][c] = count;
    }

    last_group_idx++;
}

inline bool predicate(int r, int c, int max_r, int max_c) {
    return r >= 0 && r < max_r && c >= 0 && c < max_c && map[r][c] == 0 && group[r][c] == 0;
}