/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42862">체육복</a>
 */
fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
    val lostSet = (lost.toSet() - reserve.toSet()).toMutableSet()
    val reserveSet = (reserve.toSet() - lost.toSet()).toMutableSet()

    for (item in reserveSet) {
        if (item - 1 in lostSet) lostSet.remove(item - 1)
        else if (item + 1 in lostSet) lostSet.remove(item + 1)
    }

    return n - lostSet.size
}