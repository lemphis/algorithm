#include <string>
#include <vector>

using namespace std;
using vvi = vector<vector<int>>;

vvi rotate(vvi& src) {
    int size = src.size();
    vvi dest(size, vector<int>(size));
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            dest[r][c] = src[(size - 1) - c][r];
        }
    }

    return dest;
}

/**
 * @see [자물쇠와 열쇠](https://programmers.co.kr/learn/courses/30/lessons/60059)
 */
bool solution(vvi& key, vvi& lock) {
    bool answer = true;
    int key_size = key.size();
    int lock_size = lock.size();
    return answer;
}