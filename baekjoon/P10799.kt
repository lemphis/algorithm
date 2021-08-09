import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/10799">쇠막대기</a>
 */
fun main() {
    val input = readLine()!!
    val stack = Stack<Char>()
    var count = 0
    var beforePopped = false
    for (char in input) {
        if (char == '(') {
            stack.push(char)
            beforePopped = false
        } else {
            stack.pop()
            if (beforePopped) {
                count++
            } else {
                count += stack.size
            }
            beforePopped = true
        }
    }
    println(count)
}
