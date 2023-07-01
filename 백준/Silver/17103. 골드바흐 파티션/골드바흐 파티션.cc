#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1'000'001;

int main() {
    int T;
    scanf("%d", &T);

    bool check_prime[MAX];
    memset(check_prime, 0, sizeof(check_prime));
    vector<int> primes;
    for (int i = 2; i < MAX; ++i) {
        if (!check_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < MAX; j += i) {
                check_prime[j] = 1;
            }
        }
    }

    while (T--) {
        int N;
        scanf("%d", &N);
        int count = 0;
        for (int i = 0; primes[i] < N; ++i) {
            if (!check_prime[N - primes[i]]) {
                count++;
                if (N - primes[i] == primes[i]) {
                    count++;
                }
            }
        }
        printf("%d\n", count / 2);
    }

    return 0;
}