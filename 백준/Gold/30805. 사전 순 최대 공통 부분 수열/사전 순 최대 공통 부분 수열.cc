#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int M;
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    int max_common = 0;
    int max_common_a_idx = -1;
    int max_common_b_idx = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i] == B[j] && A[i] > max_common) {
                max_common = A[i];
                max_common_a_idx = i;
                max_common_b_idx = j;
            }
        }
    }

    if (max_common == 0) {
        cout << 0;
        return 0;
    }

    vector<int> ans;
    while (max_common > 0) {
        ans.push_back(max_common);
        max_common = 0;
        int temp_b_idx = max_common_b_idx;
        for (int i = max_common_a_idx + 1; i < N; ++i) {
            for (int j = temp_b_idx + 1; j < M; ++j) {
                if (A[i] == B[j] && A[i] > max_common) {
                    max_common = A[i];
                    max_common_a_idx = i;
                    max_common_b_idx = j;
                }
            }
        }
    }

    cout << ans.size() << endl;
    for (int num : ans) {
        cout << num << ' ';
    }

    return 0;
}