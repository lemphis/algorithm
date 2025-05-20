#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check_knight_tour(int r, int c, int before_r, int before_c);

int main() {
    fastio;

    bool visited[6][6];
    memset(visited, 0, sizeof(visited));

    string pos;
    bool pass = true;
    int before_r, before_c;
    int first_r, first_c, last_r, last_c;
    for (int i = 0; i < 36; ++i) {
        cin >> pos;
        int r = pos[1] - '0' - 1;
        int c = pos[0] - 'A';

        if (i == 0) {
            first_r = r;
            first_c = c;
        }
        if (i == 35) {
            last_r = r;
            last_c = c;
        }

        if (visited[r][c] ||
            (i > 0 && !check_knight_tour(r, c, before_r, before_c))) {
            pass = false;
            break;
        }

        visited[r][c] = true;
        before_r = r;
        before_c = c;
    }

    if (pass && !check_knight_tour(first_r, first_c, last_r, last_c)) {
        pass = false;
    }

    cout << (pass ? "Valid" : "Invalid");

    return 0;
}

bool check_knight_tour(int r, int c, int before_r, int before_c) {
    return (abs(r - before_r) == 2 && abs(c - before_c) == 1) ||
           (abs(c - before_c) == 2 && abs(r - before_r) == 1);
}