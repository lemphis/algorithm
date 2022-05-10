/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/81301">숫자 문자열과 영단어</a>
 */
fun solution(s: String): Int {
	val eng = mapOf(
		"zero" to "0",
		"one" to "1",
		"two" to "2",
		"three" to "3",
		"four" to "4",
		"five" to "5",
		"six" to "6",
		"seven" to "7",
		"eight" to "8",
		"nine" to "9"
	)

	var answer = s
	eng.forEach { answer = answer.replace(it.key, it.value) }

	return answer.toInt()
}