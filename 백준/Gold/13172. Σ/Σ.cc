#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const long DIV = 1'000'000'007;

long mod_pow(long base, int exp);

int main() {
    fastio;

    int M;
    cin >> M;
    long sum = 0;
    while (M--) {
        long N, S;
        cin >> N >> S;
        sum = ((S * mod_pow(N, DIV - 2)) % DIV + sum) % DIV;
    }

    cout << sum;

    return 0;
}

long mod_pow(long base, int exp) {
    if (exp == 1) {
        return base;
    }

    long ans = mod_pow(base, exp / 2) % DIV;
    ans = (ans * ans) % DIV;

    return exp & 1 ? (ans * base) % DIV : ans;
}