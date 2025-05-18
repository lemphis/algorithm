#include <unordered_set>
#include <vector>

using namespace std;

int solution(int N, int number) {
    if (N == number) {
        return 1;
    }

    vector<unordered_set<int>> dp(9);
    for (int i = 1; i <= 8; ++i) {
        int concatenated = 0;
        for (int k = 0; k < i; ++k) {
            concatenated = concatenated * 10 + N;
        }
        dp[i].insert(concatenated);

        for (int a = 1; a < i; ++a) {
            int b = i - a;
            for (int first : dp[a]) {
                for (int second : dp[b]) {
                    dp[i].insert(first + second);
                    dp[i].insert(first - second);
                    dp[i].insert(first * second);
                    if (second != 0) {
                        dp[i].insert(first / second);
                    }
                }
            }
        }
        if (dp[i].count(number)) {
            return i;
        }
    }

    return -1;
}