#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, L;
    cin >> N >> L;

    int before_pos = 0, time = 0;
    for (int i = 0; i < N; ++i) {
        int D, R, G;
        cin >> D >> R >> G;

        time += D - before_pos;
        if (time % (R + G) < R) {
            time += R - (time % (R + G));
        }
        before_pos = D;
    }

    cout << time + (L - before_pos);

    return 0;
}