/**
 * @see <a href="https://www.acmicpc.net/problem/3273">두 수의 합</a>
 */
fun main() {
    val size = readLine()!!.toInt()
    val numbers = readLine()!!
        .split(" ")
        .map { it.toInt() }
        .sorted()
    val target = readLine()!!.toInt()

    val indexOfFirst = numbers.indexOfFirst { it >= target }
    val filtered = if (indexOfFirst == -1) numbers else numbers.slice(0 until indexOfFirst)
    var start = 0
    var end = filtered.size - 1

    var count = 0
    while (start < end) {
        val sum = filtered[start] + filtered[end]
        if (sum == target) {
            count++
            start++
        } else if (sum > target) {
            end--
        } else {
            start++
        }
    }

    println(count)
}