/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42578">위장</a>
 */
fun solution(clothes: Array<Array<String>>): Int =
	clothes
		.groupBy { it[1] }
		.map { it.value.size }
		.fold(1) { acc, cur -> acc * (cur + 1) } - 1