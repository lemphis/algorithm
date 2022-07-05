/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/77484">로또의 최고 순위와 최저 순위</a>
 */
fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
	val duplicateCount = win_nums.groupBy { it }.filter { lottos.contains(it.key) }.count()
	val zeroCount = lottos.count { it == 0 }
	val min = if (duplicateCount == 0) 6 else 7 - duplicateCount
	var max = 7 - zeroCount - duplicateCount
	if (duplicateCount + zeroCount == 6) max = 1
	if (duplicateCount + zeroCount == 0) max = 6

	return intArrayOf(max, min)
}