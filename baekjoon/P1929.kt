import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/1929">소수 구하기</a>
 */
fun main() {
    val MN = StringTokenizer(readLine())
    val M = MN.nextToken().toInt()
    val N = MN.nextToken().toInt()
    val arr = Array<Int>(1_000_001) { it + 1 }
    arr[1] = 0
    for (i in 2..N) {
        if (arr[i] == 0) continue
        for (j in (i * 2)..N step i) {
            arr[j] = 0
        }
    }
    for (i in M..N) {
        if (arr[i] != 0) {
            println(i)
        }
    }
}