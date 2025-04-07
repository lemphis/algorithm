#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    queue<int> q;
    int max_len = 0;
    int min_num = 1e9;
    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            int num;
            cin >> num;
            q.push(num);
            if (q.size() > max_len ||
                (q.size() == max_len && q.back() < min_num)) {
                max_len = q.size();
                min_num = q.back();
            }
        } else {
            q.pop();
        }
    }

    cout << max_len << ' ' << min_num;

    return 0;
}