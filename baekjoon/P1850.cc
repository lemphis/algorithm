#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::string;

long gcd(long a, long b);

/**
 * @see [최대공약수](https://www.acmicpc.net/problem/1850)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long A, B;
    cin >> A >> B;
    if (A < B) {
        long temp = A;
        A = B;
        B = temp;
    }
    long count = gcd(A, B);
    string answer = "";
    for (int i = 0; i < count; ++i) {
        answer.append("1");
    }
    cout << answer << endl;
}

long gcd(long a, long b) { return a % b == 0 ? b : gcd(b, a % b); }