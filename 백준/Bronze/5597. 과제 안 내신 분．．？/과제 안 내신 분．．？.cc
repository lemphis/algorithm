#include <iostream>
#include <algorithm>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int arr[30] = {0};
    for (int i = 0; i < 28; ++i) {
        int num;
        cin >> num;
        arr[num - 1] = 1;
    }
    
    for (int i = 0; i < 30; ++i) {
        if (arr[i] == 0) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}