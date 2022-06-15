/**
 * @see <a href="https://www.acmicpc.net/problem/17219">비밀번호 찾기</a>
 */
fun main() {
	val (N, M) = readln().split(' ').map(String::toInt)
	val map = mutableMapOf<String, String>()
	repeat(N) {
		val (key, value) = readln().split(' ')
		map[key] = value
	}
	repeat(M) {
		val key = readln()
		println(map[key])
	}
}