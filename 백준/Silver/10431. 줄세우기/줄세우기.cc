#include <iostream>
#include <sstream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int P;
    cin >> P;
    ostringstream output;

    while (P--) {
        int t;
        cin >> t;
        int heights[20];
        for (int i = 0; i < 20; ++i) {
            cin >> heights[i];
        }

        int move_count = 0;
        for (int i = 1; i < 20; ++i) {
            int j = i;
            while (j > 0 && heights[j - 1] > heights[j]) {
                swap(heights[j - 1], heights[j]);
                ++move_count;
                --j;
            }
        }

        cout << t << ' ' << move_count << endl;
    }

    cout << output.str();

    return 0;
}
