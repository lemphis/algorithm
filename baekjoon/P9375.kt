import java.util.*
import kotlin.collections.HashMap

/**
 * @see <a href="https://www.acmicpc.net/problem/9375">패션왕 신해빈</a>
 */
fun main() {
    val testcase = readLine()!!
    val map = HashMap<String, Int>()
    for (i in 0 until testcase.toInt()) {
        val clothes = readLine()!!
        for (j in 0 until clothes.toInt()) {
            val tokens = StringTokenizer(readLine())
            val item = tokens.nextToken()
            val kind = tokens.nextToken()
            map[kind] = map[kind]?.plus(1) ?: 1
        }
        println(map.toList().fold(1) { acc, cur -> acc * (cur.second + 1) } - 1)
        map.clear()
    }
}