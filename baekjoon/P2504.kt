import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/2504">괄호의 값</a>
 */
fun main() {
    val input = readLine()!!
    val stack = Stack<Char>()
    var sum = 0
    var temp = 0
    var lastStackSize = 0
    var before: Char? = null
    input.forEach {
        if (isStartBracket(it)) {
            if (!isStartBracket(before)) {
                sum += temp
                temp = 0
            }
            stack.push(it)
        } else {
            if (stack.size == 0 || !isPair(stack.peek(), it)) {
                println(0)
                return
            }
            stack.pop()
            when (before) {
                '(', '[' -> {
                    lastStackSize = stack.size
                    temp += if (before == '(') 2 else 3
                }
                ')', ']' -> {
                    if (lastStackSize == stack.size) {

                    } else {
                        temp *= if (before == ')') 2 else 3
                    }
                }
            }
        }
        println(temp)
        before = it
    }
    println(sum + temp)
}

fun isStartBracket(char: Char?): Boolean = char == '(' || char == '['
fun isPair(start: Char, end: Char): Boolean = (start == '(' && end == ')') || (start == '[' && end == ']')