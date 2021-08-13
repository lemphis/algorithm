/**
 * @see <a href="https://www.acmicpc.net/problem/10212">Mystery</a>
 */
fun main() {
    val toggle = (Math.random() * 2 + 1).toInt()
    println(if (toggle == 1) "Yonsei" else "Korea")
}