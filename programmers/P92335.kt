import kotlin.math.sqrt

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/92335">k진수에서 소수 개수 구하기</a>
 */
class Solution {
	fun solution(n: Int, k: Int): Int = n.toString(k)
		.split("0")
		.count { it.isNotEmpty() && it.toLong().isPrime() }

	private fun Long.isPrime(): Boolean {
		if (this == 1L) {
			return false
		}

		for (i in 2..sqrt(this.toDouble()).toLong()) {
			if (this % i == 0L) {
				return false
			}
		}
		return true
	}
}