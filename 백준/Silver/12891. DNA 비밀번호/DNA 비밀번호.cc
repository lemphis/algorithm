#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int S, P;
    cin >> S >> P;
    string dna;
    cin >> dna;
    int a, c, g, t;
    cin >> a >> c >> g >> t;

    int a_count = 0;
    int c_count = 0;
    int g_count = 0;
    int t_count = 0;
    for (int i = 0; i < P; ++i) {
        switch (dna[i]) {
            case 'A':
                a_count += 1;
                break;
            case 'C':
                c_count += 1;
                break;
            case 'G':
                g_count += 1;
                break;
            case 'T':
                t_count += 1;
                break;
            default:
                break;
        }
    }

    int count = 0;
    if (a_count >= a && c_count >= c && g_count >= g && t_count >= t) {
        count += 1;
    }
    for (int i = P; i < S; ++i) {
        switch (dna[i]) {
            case 'A':
                a_count += 1;
                break;
            case 'C':
                c_count += 1;
                break;
            case 'G':
                g_count += 1;
                break;
            case 'T':
                t_count += 1;
                break;
            default:
                break;
        }
        switch (dna[i - P]) {
            case 'A':
                a_count -= 1;
                break;
            case 'C':
                c_count -= 1;
                break;
            case 'G':
                g_count -= 1;
                break;
            case 'T':
                t_count -= 1;
                break;
            default:
                break;
        }
        if (a_count >= a && c_count >= c && g_count >= g && t_count >= t) {
            count += 1;
        }
    }

    cout << count;

    return 0;
}