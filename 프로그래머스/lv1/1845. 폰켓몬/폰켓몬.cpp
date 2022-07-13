#include <map>
#include <vector>

using namespace std;

/**
 * @see [폰켓몬](https://programmers.co.kr/learn/courses/30/lessons/1845)
 */
int solution(vector<int> nums) {
    map<int, int> map;
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        map[*iter]++;
    }

    return map.size() > nums.size() / 2 ? nums.size() / 2 : map.size();
}