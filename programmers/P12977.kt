import kotlin.math.sqrt

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/12977">소수 만들기</a>
 */
fun solution(nums: IntArray): Int {
	val size = nums.size
	val sieve = MutableList(3000) { 1 }
	sieve[0] = 0
	sieve[1] = 0
	for (i in 2 until sqrt(3000.0).toInt()) {
		if (sieve[i] == 1) {
			var times = 2
			while (i * times < 3000) {
				sieve[i * times] = 0
				times++
			}
		}
	}

	var count = 0
	for (i in 0 until size) {
		for (j in i + 1 until size) {
			for (k in j + 1 until size) {
				if (sieve[nums[i] + nums[j] + nums[k]] == 1) {
					count++
				}
			}
		}
	}

	return count
}