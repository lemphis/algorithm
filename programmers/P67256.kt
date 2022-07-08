import kotlin.math.abs

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/67256">키패드 누르기</a>
 */
fun solution(numbers: IntArray, hand: String): String {
	val leftSide = listOf(1, 4, 7)
	val rightSide = listOf(3, 6, 9)
	var leftPos = Pair(3, 0)
	var rightPos = Pair(3, 2)
	val result = mutableListOf<Char>()
	numbers.forEach {
		val nowHand: Char = when (it) {
			in leftSide -> {
				leftPos = getPos(it)
				'L'
			}
			in rightSide -> {
				rightPos = getPos(it)
				'R'
			}
			else -> {
				val next = getPos(it)
				val leftDiff = abs(leftPos.first - next.first) + abs(leftPos.second - next.second)
				val rightDiff = abs(rightPos.first - next.first) + abs(rightPos.second - next.second)
				if (leftDiff > rightDiff) {
					rightPos = next
					'R'
				} else if (leftDiff < rightDiff) {
					leftPos = next
					'L'
				} else {
					if (hand == "right") {
						rightPos = next
						'R'
					} else {
						leftPos = next
						'L'
					}
				}
			}
		}
		result.add(nowHand)
	}

	return result.joinToString("")
}

fun getPos(num: Int) = when (num) {
	1 -> Pair(0, 0)
	2 -> Pair(0, 1)
	3 -> Pair(0, 2)
	4 -> Pair(1, 0)
	5 -> Pair(1, 1)
	6 -> Pair(1, 2)
	7 -> Pair(2, 0)
	8 -> Pair(2, 1)
	9 -> Pair(2, 2)
	0 -> Pair(3, 1)
	else -> throw IllegalArgumentException()
}