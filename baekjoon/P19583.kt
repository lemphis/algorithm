/**
 * @see <a href="https://www.acmicpc.net/problem/19583">싸이버개강총회</a>
 */
fun main() {
	val (S, E, Q) = readln().split(' ')
	val map = mutableMapOf<String, Pair<Boolean, Boolean>>()
	while (true) {
		val line = readLine() ?: break
		val (time, name) = line.split(' ')
		if (map[name] == null) map[name] = false to false
		if (time <= S) map[name] = true to map[name]!!.second
		if (time in E..Q) map[name] = map[name]!!.first to true
	}

	println(map.count { it.value.first && it.value.second })
}