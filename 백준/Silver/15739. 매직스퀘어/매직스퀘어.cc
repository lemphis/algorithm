#include <iostream>
#include <unordered_set>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<int>>;

int main() {
    fastio;

    int N;
    cin >> N;
    vvi matrix(N, vector<int>(N));
    unordered_set<int> set;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> matrix[r][c];
            set.insert(matrix[r][c]);
        }
    }

    if (set.size() < N * N) {
        cout << "FALSE";
        return 0;
    }

    int result_sum = N * (N * N + 1) / 2;
    for (int r = 0; r < N; ++r) {
        int sum = 0;
        for (int c = 0; c < N; ++c) {
            sum += matrix[r][c];
        }
        if (result_sum != sum) {
            cout << "FALSE";
            return 0;
        }
    }

    for (int c = 0; c < N; ++c) {
        int sum = 0;
        for (int r = 0; r < N; ++r) {
            sum += matrix[r][c];
        }
        if (result_sum != sum) {
            cout << "FALSE";
            return 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][i];
    }
    if (result_sum != sum) {
        cout << "FALSE";
        return 0;
    }

    sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][N - 1 - i];
    }
    if (result_sum != sum) {
        cout << "FALSE";
        return 0;
    }

    cout << "TRUE";

    return 0;
}