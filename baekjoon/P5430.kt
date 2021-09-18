/**
 * @see <a href="https://www.acmicpc.net/problem/5430">AC</a>
 */
fun main() {
    val T = readLine()!!.toInt()
    for (i in 0 until T) {
        val p = readLine()!!
        val arrLength = readLine()!!.toInt()
        val dq = ArrayDeque<Int>()
        val arr = readLine()!!
            .replace("""[\[\]]""".toRegex(), "")
            .split(",")
            .forEach { if (it != "") dq.addLast(it.toInt()) }
        var isError = false
        var isReverse = false
        for (it in p) {
            if (it == 'R') {
                isReverse = !isReverse
            } else if (it == 'D') {
                if (dq.size == 0) {
                    isError = true
                    break
                }
                if (isReverse) {
                    dq.removeLast()
                } else {
                    dq.removeFirst()
                }
            }
        }
        if (isError) {
            println("error")
        } else {
            val target = if (isReverse) dq.reversed() else dq
            val replaced = target.toString().replace(" ", "")
            println(replaced)
        }
    }
}