import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/9012">괄호</a>
 */
fun main() {
    val inputCount = readLine()!!
    for (i in 0 until inputCount.toInt()) {
        var result = "YES"
        val stack = Stack<Char>()
        for (it in readLine()!!) {
            if (it == '(') {
                stack.push(it)
            } else {
                if (stack.empty()) {
                    result = "NO"
                    break
                }
                val pop = stack.pop()
                if (pop == ')') {
                    result = "NO"
                    break
                }
            }
        }
        if (stack.size != 0) {
            result = "NO"
        }
        println(result)
    }
}