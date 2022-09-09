fun main() {
	val (N, L) = readln().split(' ').map { it.toInt() }
	for (i in L..100) {
		val quotient = N / i
		val start = quotient - (i / 2 - if (i.and(1) == 0) 1 else 0)
		if (start < 0) break
		val range = start until start + i
		if (range.sum() == N) {
			range.forEach { print("$it ") }
			return
		}
	}
	println(-1)
}