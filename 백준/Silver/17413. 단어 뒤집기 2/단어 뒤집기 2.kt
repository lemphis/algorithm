import java.util.*

fun main(args: Array<String>) {
    val builder = StringBuilder()
    val stack = Stack<Char>()
    var isReverse = true
    readLine()!!.map {
        if (it == '<') {
            isReverse = false
            while (!stack.isEmpty()) {
                builder.append(stack.pop())
            }
            builder.append(it)
        } else if (it == '>') {
            isReverse = true
            builder.append(it)
        } else if (it == ' ') {
            if (isReverse) {
                while (!stack.isEmpty()) {
                    builder.append(stack.pop())
                }
            }
            builder.append(it)
        } else {
            if (isReverse) stack.push(it) else builder.append(it)
        }
    }
    if (!stack.isEmpty()) {
        while (!stack.isEmpty()) {
            builder.append(stack.pop())
        }
    }
    println(builder)
}