fun main(args: Array<String>) {
	val map = mutableMapOf<String, Int>()
	var count = 0
	while (true) {
		val kind: String = readLine() ?: break
		map[kind] = map.getOrDefault(kind, 0) + 1
		count++
	}
	val builder = StringBuilder()
	map.toList()
		.sortedBy { it.first }
		.forEach { builder.append(it.first + " " + String.format("%.4f", it.second.toDouble() / count * 100) + "\n") }
	println(builder)
}