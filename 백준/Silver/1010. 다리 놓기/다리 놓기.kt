import java.math.BigInteger

val memo = Array(30) { BigInteger("0") }

fun main() {
	memo[0] = BigInteger.ONE
	memo[1] = BigInteger.ONE
	repeat(readln().toInt()) {
		val (N, M) = readln().split(' ').map { it.toInt() }
		println(factorial(M) / (factorial(N) * factorial(M - N)))
	}
}

private fun factorial(num: Int): BigInteger {
	if (memo[num] > BigInteger.ZERO) return memo[num]
	memo[num] = BigInteger(num.toString()) * factorial(num - 1)
	return memo[num]
}