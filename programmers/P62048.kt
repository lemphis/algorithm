/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/62048">멀쩡한 사각형</a>
 */
fun solution(w: Int, h: Int): Long = w.toLong() * h.toLong() - (w + h - gcd(w, h))

fun gcd(a: Int, b: Int): Int = if (a % b == 0) b else gcd(b, a % b)