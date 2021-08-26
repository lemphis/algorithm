import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/1929">소수 구하기</a>
 */
fun main() {
    val input = StringTokenizer(readLine())
    val m = input.nextToken().toInt()
    val n = input.nextToken().toInt()
    val arr = Array<Int>(1_000_001) { it + 1 }
    arr[1] = 0
    for (i in 2..n) {
        if (arr[i] == 0) continue
        for (j in (i * 2)..n step i) {
            arr[j] = 0
        }
    }
    for (i in m..n) {
        if (arr[i] != 0) {
            println(i)
        }
    }
}