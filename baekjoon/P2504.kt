import java.util.*

/**
 * @see <a href="https://www.acmicpc.net/problem/2504">괄호의 값</a>
 */
fun main() {
    val input = readLine()!!
    val stack = Stack<String>()
    var errorCode = 0
    for (it in input) {
        val str = it.toString()
        if (str == "(" || str == "[") {
            stack.push(str)
        } else {
            if (stack.size == 0) {
                errorCode = -1
                break
            }
            val numStr = when (str) {
                ")" -> "2"
                "]" -> "3"
                else -> "-1"
            }
            if (numStr == "-1") {
                errorCode = -1
                break
            }
            if ((stack.peek() == "[" && str == "]") || (stack.peek() == "(" && str == ")")) {
                stack.pop()
                stack.push(numStr)
            } else if ((stack.peek() == "(" && str == "]") || (stack.peek() == "[" && str == ")")) {
                errorCode = -1
            } else {
                errorCode = getNum(stack, numStr, if (str == ")") "(" else "[")
            }
            if (errorCode == -1) {
                break
            }
        }
    }
    if (errorCode == -1
        || stack.contains("[") || stack.contains("(")
        || stack.contains("]") || stack.contains(")")
    ) {
        println(0)
        return
    }
    print(stack.reduce { acc, s -> (acc.toInt() + s.toInt()).toString() }.toInt())
}

fun getNum(stack: Stack<String>, numStr: String, findTarget: String): Int {
    var errorCode = 0
    try {
        if (stack.find { it == findTarget }.isNullOrEmpty()) {
            errorCode = -1
        }
        var acc = stack.pop()
        while (stack.peek() != findTarget) {
            if (stack.isEmpty()) {
                break
            }
            val pop = stack.pop()
            acc = (pop.toInt() + acc.toInt()).toString()
        }
        acc *= numStr
        stack.pop()
        stack.push(acc)
    } catch (e: Exception) {
        errorCode = -1
    }
    return errorCode
}

operator fun String.times(other: String): String = (this.toInt() * other.toInt()).toString()