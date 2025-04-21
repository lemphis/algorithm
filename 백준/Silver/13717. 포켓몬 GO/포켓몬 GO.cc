#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    int sum = 0;
    int max = 0;
    string max_count_name;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        int K, M;
        cin >> K >> M;
        int q = M / K;
        int r = M % K + q * 2;
        while (r >= K) {
            int temp_q = r / K;
            q += temp_q;
            r = r % K + temp_q * 2;
        }
        if (max < q) {
            max = q;
            max_count_name = name;
        }
        sum += q;
    }

    cout << sum << endl << max_count_name;

    return 0;
}