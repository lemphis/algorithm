/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/70128">내적</a>
 */
fun solution(a: IntArray, b: IntArray) = a.foldIndexed(0) { idx, acc, cur -> acc + cur * b[idx] }