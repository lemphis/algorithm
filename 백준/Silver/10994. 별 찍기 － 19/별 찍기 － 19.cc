#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = (100 - 1) * 4 + 1;
bool map[MAX][MAX];

void draw(int N, int depth);

int main() {
    fastio;
    int N;
    cin >> N;
    draw(N, 0);

    for (int r = 0; r < (N - 1) * 4 + 1; ++r) {
        for (int c = 0; c < (N - 1) * 4 + 1; ++c) {
            cout << (map[r][c] ? '*' : ' ');
        }
        cout << endl;
    }

    return 0;
}

void draw(int N, int depth) {
    if (N == 0) {
        return;
    }
    int count = (N - 1) * 4 + 1;
    for (int r = depth * 2; r < depth * 2 + count; ++r) {
        for (int c = depth * 2; c < depth * 2 + count; ++c) {
            if (r == depth * 2 || r == depth * 2 + count - 1 || c == depth * 2 || c == depth * 2 + count - 1) {
                map[r][c] = 1;
            }
        }
    }
    draw(N - 1, depth + 1);
}