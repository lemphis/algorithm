fun main() {
	val (X, Y) = readln().split(' ').map { it.toLong() }
	val percent = 100 * Y / X
	if (percent >= 99) {
		println(-1)
		return
	}
	var lo = 0L
	var hi = X
	while (lo + 1 < hi) {
		val mid = (lo + hi) / 2
		if ((100 * (Y + mid) / (X + mid)) == percent) lo = mid
		else hi = mid
	}
	println(hi)
}