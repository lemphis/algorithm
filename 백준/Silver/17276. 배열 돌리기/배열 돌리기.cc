#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using vvi = vector<vector<int>>;

void rotate(vvi& arr, int n, int rotate_count);

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int n, degree;
        cin >> n >> degree;
        vvi arr(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        if (degree < 0) {
            degree += 360;
        }
        rotate(arr, n, degree / 45);
    }

    return 0;
}

void rotate(vvi& arr, int n, int rotate_count) {
    vvi rotated(arr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[i][j] = arr[i][j];
        }
    }
    while (rotate_count--) {
        vvi temp(rotated);
        for (int i = 0; i < n; ++i) {
            temp[i][n / 2] = rotated[i][i];
        }
        for (int i = 0; i < n; ++i) {
            temp[i][(n - 1) - i] = rotated[i][n / 2];
        }
        for (int i = 0; i < n; ++i) {
            temp[n / 2][(n - 1) - i] = rotated[i][(n - 1) - i];
        }
        for (int i = 0; i < n; ++i) {
            temp[i][i] = rotated[n / 2][i];
        }
        rotated = temp;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << rotated[i][j] << ' ';
        }
        cout << endl;
    }
}