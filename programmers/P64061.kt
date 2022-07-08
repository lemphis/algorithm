import java.util.Stack

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/64061">크레인 인형뽑기 게임</a>
 */
fun solution(board: Array<IntArray>, moves: IntArray): Int {
	val stack = Stack<Int>()
	val boardSize = board.size
	var count = 0
	moves.forEach {
		var target = 0
		for (i in 0 until boardSize) {
			if (board[i][it - 1] != 0) {
				target = board[i][it - 1]
				board[i][it - 1] = 0
				break
			}
		}
		if (target != 0) {
			if (!stack.empty() && stack.peek() == target) {
				stack.pop()
				count += 2
			} else {
				stack.push(target)
			}
		}
	}

	return count
}