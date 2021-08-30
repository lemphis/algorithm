/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42579">베스트앨범</a>
 */
class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        val answer = ArrayList<Int>()
        val sum = HashMap<String, Int>()
        genres.forEachIndexed { i, genre -> sum[genre] = sum[genre]?.plus(plays[i]) ?: plays[i] }
        val sorted = sum.toList().sortedByDescending { it.second }
        sorted.forEach { genre ->
            var count = 0
            genres
                .mapIndexed { idx, item -> Triple(idx, item, plays[idx]) }
                .filter { genre.first == it.second }
                .sortedByDescending { it.third }
                .forEach {
                    if (count < 2) {
                        answer.add(it.first)
                        count++
                    }
                }
            count = 0
        }
        return answer.toIntArray()
    }
}