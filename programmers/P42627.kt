/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42627">디스크 컨트롤러</a>
 */
class Solution {
    fun solution(jobs: Array<IntArray>): Int {
        var answer = 0
        val size = jobs.size
        val jobList = jobs
            .sortedWith(compareBy({ it[0] }, { it[1] }))
            .toMutableList()
        return answer
    }
}