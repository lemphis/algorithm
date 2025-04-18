#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;

    unordered_map<string, int> stoi;
    vector<string> itos;
    vector<int> parent(100000, -1);
    int idx = 0;

    for (int i = 0; i < N - 1; ++i) {
        string A, B;
        cin >> A >> B;

        if (stoi.find(A) == stoi.end()) {
            stoi[A] = idx++;
            itos.push_back(A);
        }
        if (stoi.find(B) == stoi.end()) {
            stoi[B] = idx++;
            itos.push_back(B);
        }

        parent[stoi[A]] = stoi[B];
    }

    string A, B;
    cin >> A >> B;

    int a = stoi[A];
    int b = stoi[B];

    int temp = b;
    while (temp != -1) {
        if (temp == a) {
            cout << 1;
            return 0;
        }
        temp = parent[temp];
    }

    temp = a;
    while (temp != -1) {
        if (temp == b) {
            cout << 1;
            return 0;
        }
        temp = parent[temp];
    }

    cout << 0;

    return 0;
}