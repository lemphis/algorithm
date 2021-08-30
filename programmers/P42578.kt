/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42578">위장</a>
 */
class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        var answer = 1
        val flat = clothes.map { it[1] }
        val map = HashMap<String, Int>()
        for (it in flat) map[it] = map[it]?.plus(1) ?: 1
        for (it in map) answer *= (it.value + 1)
        return answer - 1
    }
}