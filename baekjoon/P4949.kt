import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/4949">균형잡힌 세상</a>
 */
fun main() {
    while (true) {
        val line = readLine()!!
        if (line == ".") {
            return
        }
        var count = 0
        val stack = Stack<Char>()
        for (char in line) {
            if (char == '(' || char == '[') {
                stack.push(char)
                count++
                continue
            }
            if (char == ')' || char == ']') {
                count++
                if (stack.size == 0) {
                    break
                }
                if ((stack.peek() == '(' && char == ']') || (stack.peek() == '[' && char == ')')) {
                    break
                }
                if ((stack.peek() == '(' && char == ')') || (stack.peek() == '[' && char == ']')) {
                    stack.pop()
                }
            }
        }
        println(if (stack.size == 0 && count % 2 == 0) "yes" else "no")
    }
}
