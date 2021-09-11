#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

int gcd(int a, int b);

/**
 * @see [분수 합](https://www.acmicpc.net/problem/1735)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int first_numerator, first_denominator, second_numerator, second_denominator;
    cin >> first_numerator >> first_denominator >> second_numerator >> second_denominator;
    int new_denominator = first_denominator * second_denominator / gcd(first_denominator, second_denominator);
    int new_numerator = (new_denominator / first_denominator * first_numerator) + (new_denominator / second_denominator * second_numerator);
    int divisor = gcd(new_numerator, new_denominator);
    cout << new_numerator / divisor << ' ' << new_denominator / divisor << endl;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}