/**
 * @see <a href="https://www.acmicpc.net/problem/1919">애너그램 만들기</a>
 */
fun main(args: Array<String>) {
    val first = readLine()!!
    var second = readLine()!!
    val firstLength = first.length
    val secondLength = second.length
    var count = 0
    for (i in first) {
        for ((idx, j) in second.withIndex()) {
            if (i == j) {
                count += 2
                second = second.removeRange(idx, idx + 1)
                break
            }
        }
    }
    println(firstLength + secondLength - count)
}