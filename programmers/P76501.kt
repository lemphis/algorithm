/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/76501">음양 더하기</a>
 */
fun solution(absolutes: IntArray, signs: BooleanArray): Int =
	signs.mapIndexed { idx, plus -> if (plus) absolutes[idx] else -absolutes[idx] }.sum()