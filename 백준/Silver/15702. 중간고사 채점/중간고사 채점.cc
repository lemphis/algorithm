#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }
    int max_score_student = 0, max_score = -1;
    for (int i = 0; i < M; ++i) {
        int student;
        cin >> student;
        int score = 0;
        for (int j = 0; j < N; ++j) {
            char c;
            cin >> c;
            if (c == 'O') {
                score += scores[j];
            }
        }
        if (score > max_score ||
            (score == max_score && max_score_student > student)) {
            max_score_student = student;
            max_score = score;
        }
    }

    cout << max_score_student << ' ' << max_score;

    return 0;
}