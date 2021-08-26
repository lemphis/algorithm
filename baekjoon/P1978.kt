import java.util.*
import kotlin.math.sqrt

/**
 * @see <a href="https://www.acmicpc.net/problem/1978">소수 찾기</a>
 */
fun main() {
    val n = readLine()!!
    val nums = StringTokenizer(readLine())
    var exclude = 0
    while (nums.hasMoreTokens()) {
        val num = nums.nextToken().toInt()
        if (num == 1) {
            exclude++
            continue
        }
        val sqrt = sqrt(num.toFloat()).toInt()
        for (i in 2..sqrt) {
            if (num % i == 0) {
                exclude++
                break
            }
        }
    }
    println(n.toInt() - exclude)
}