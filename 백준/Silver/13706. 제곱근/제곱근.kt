import java.math.BigInteger

fun main() {
	val num = BigInteger(readLine()!!)
	if (num == BigInteger("1")) {
		println(1)
		return
	}
	var lo = BigInteger("0")
	var hi = num.divide(BigInteger("2")).add(BigInteger("1"))
	while (lo.add(BigInteger("1")) < hi) {
		val mid = lo.add(hi).divide(BigInteger("2"))
		if (mid.pow(2) > num) hi = mid
		else lo = mid
	}

	println(lo)
}