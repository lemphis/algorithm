import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigInteger

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = br.readLine().split(' ')
    println(
        factorial(BigInteger(n)).divide(
            factorial(BigInteger(m)).multiply(
                factorial(
                    BigInteger(n).subtract(
                        BigInteger(m)
                    )
                )
            )
        )
    )
}

fun factorial(n: BigInteger): BigInteger =
    if (n == BigInteger.ONE) BigInteger.ONE else n.multiply(factorial(n.subtract(BigInteger.ONE)))