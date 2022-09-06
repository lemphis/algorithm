import java.math.BigInteger

fun main() {
	val (A, B) = readln().split(' ').map { BigInteger(it) }
	println(A + B)
}