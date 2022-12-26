import java.util.LinkedList
import java.util.Queue

fun main() {
    val N = readln().toInt()
    val queue: Queue<Int> = LinkedList()
    while (true) {
        val num = readln().toInt()
        if (num == -1) {
            if (queue.isEmpty()) {
                println("empty")
            } else {
                for (item in queue) {
                    print("$item ")
                }
            }
            break
        } else if (num == 0) {
            queue.poll()
        } else {
            if (queue.size < N) {
                queue.add(num)
            }
        }
    }
}