#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int PAPER_SIZE = 10;
bool paper[PAPER_SIZE][PAPER_SIZE];
int rest[] = {5, 5, 5, 5, 5};
int sum = 0xffffffff >> 1;

void dfs(int depth);
bool is_empty_paper();
bool is_over();
bool check_n(int n, int r, int c);
void fill_paper(int n, int r, int c, bool value);

int main() {
    fastio;
    int zero_count = 0;
    for (int i = 0; i < PAPER_SIZE; ++i) {
        for (int j = 0; j < PAPER_SIZE; ++j) {
            cin >> paper[i][j];
            if (!paper[i][j]) {
                ++zero_count;
            }
        }
    }

    if (zero_count == 100) {
        cout << 0;
        return 0;
    }

    dfs(0);

    cout << (sum == 0xffffffff >> 1 ? -1 : sum);

    return 0;
}

void dfs(int depth) {
    if (sum <= depth) {
        return;
    }
    if (is_over()) {
        return;
    }
    if (is_empty_paper()) {
        if (depth < sum) {
            sum = depth;
        }
        return;
    }
    for (int r = 0; r < PAPER_SIZE; ++r) {
        for (int c = 0; c < PAPER_SIZE; ++c) {
            if (paper[r][c]) {
                for (int k = 4; k >= 0; --k) {
                    if (check_n(k + 1, r, c)) {
                        fill_paper(k + 1, r, c, 0);
                        dfs(depth + 1);
                        fill_paper(k + 1, r, c, 1);
                    }
                }
                return;
            }
        }
    }
}

bool is_empty_paper() {
    for (int i = 0; i < PAPER_SIZE; ++i) {
        for (int j = 0; j < PAPER_SIZE; ++j) {
            if (paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool is_over() {
    for (int i = 0; i < 5; ++i) {
        if (rest[i] < 0) {
            return true;
        }
    }
    return false;
}

bool check_n(int n, int r, int c) {
    if (n + r > PAPER_SIZE || n + c > PAPER_SIZE || rest[n - 1] <= 0) {
        return false;
    }
    for (int i = r; i < n + r; ++i) {
        for (int j = c; j < n + c; ++j) {
            if (!paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void fill_paper(int n, int r, int c, bool value) {
    for (int i = r; i < n + r; ++i) {
        for (int j = c; j < n + c; ++j) {
            paper[i][j] = value;
        }
    }
    value ? ++rest[n - 1] : --rest[n - 1];
}