fun main() {
	val builder = StringBuilder()
	repeat(readln().toInt()) {
		val (A, B) = readln().split(' ').map { it.toInt() }
		builder.append("${A * B / gcd(A, B)}\n")
	}
	println(builder)
}

fun gcd(a: Int, b: Int): Int = if (b > 0) gcd(b, a % b) else a