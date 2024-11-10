import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    br.readLine()
    var q = ArrayDeque<Int>()
    val collections = br.readLine().split(' ').withIndex().filter { it.value == "0" }
    val initValues = br.readLine().split(' ').map { it.toInt() }
    collections.forEach { (i, _) -> q.addLast(initValues[i]) }
    val m = br.readLine().toInt()
    br.readLine().split(' ').forEach { q.addFirst(it.toInt()) }
    print(q.takeLast(m).reversed().joinToString(" "))
}