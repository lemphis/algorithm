#include <cmath>
#include <iostream>
#include <map>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::map;
using std::string;

/**
 * @see [정답 비율 계산하기](https://www.acmicpc.net/problem/15595)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cout.precision(10);
    int n, num, result, memory, performance, language, length;
    double ac = 0, wa = 0;
    string id;
    map<string, int> m;
    cin >> n;
    while (n--) {
        cin >> num >> id >> result >> memory >> performance >> language >> length;
        if (id != "megalusion") {
            if (m.find(id) == m.end()) {
                m[id] = 1;
            } else {
                if (m[id] > 0)
                    m[id]++;
                else
                    continue;
            }
            if (result == 4) m[id] *= -1;
        }
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second < 0) {
            ac++;
            wa += (iter->second + 1) * -1;
        }
    }
    cout << ((ac == 0) ? 0 : (ac / (ac + wa)) * 100) << endl;
}
