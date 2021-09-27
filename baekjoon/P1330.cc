#include <iostream>

using namespace std;

#define endl '\n'

int main() {
    int A, B;
    cin >> A >> B;
    if (A > B) {
        cout << '>' << endl;
    } else if (A < B) {
        cout << '<' << endl;
    } else {
        cout << "==" << endl;
    }

    return 0;
}