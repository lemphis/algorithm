/**
 * @see <a href="https://www.acmicpc.net/problem/10867">중복 빼고 정렬하기</a>
 */
fun main() {
	readLine()!!
	readLine()!!
		.split(" ")
		.map { it.toInt() }
		.distinct()
		.sorted()
		.forEach { print("$it ") }
}