#include <algorithm>
#include <iostream>
#include <map>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

string num_strs[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    fastio;
    int M, N;
    cin >> M >> N;
    string nums[N - M + 1];
    map<string, int> map;
    for (int i = M; i <= N; ++i) {
        string s = to_string(i);
        string converted = "";
        for (int idx = 0; idx < s.length(); ++idx) {
            converted += num_strs[s[idx] - '0'];
        }
        nums[i - M] = converted;
        map.insert({converted, i});
    }

    sort(nums, nums + N - M + 1);

    for (int i = 0; i < N - M + 1; ++i) {
        cout << map[nums[i]] << ' ';
        if (i % 10 == 9) {
            cout << endl;
        }
    }

    return 0;
}