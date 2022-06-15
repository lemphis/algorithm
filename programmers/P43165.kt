/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/43165">타겟 넘버</a>
 */
fun solution(numbers: IntArray, target: Int): Int {
	var answer = 0
	val size = numbers.size
	fun dfs(idx: Int, sum: Int) {
		if (idx == size) {
			if (sum == target) {
				answer++
			}
			return
		}
		dfs(idx + 1, sum + numbers[idx])
		dfs(idx + 1, sum - numbers[idx])
	}
	dfs(0, 0)
	println(answer)
	return answer
}
