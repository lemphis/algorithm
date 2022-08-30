import java.util.LinkedList

typealias MMC = MutableList<MutableList<Char>>
typealias AAB = Array<Array<Boolean>>
typealias PII = Pair<Int, Int>

val dr = listOf(1, 0, -1, 0)
val dc = listOf(0, 1, 0, -1)

/**
 * @see <a href="https://www.acmicpc.net/problem/2933">미네랄</a>
 */
fun main() {
	val (R, C) = readInts()
	val cave = mutableListOf<MutableList<Char>>()
	for (i in 0 until R) {
		cave.add(readln().toMutableList())
	}
	val visited = Array(R) { Array(C) { false } }
	val times = readln().toInt()
	val rowNums = readInts().map { R - it }
	for (i in 0 until times) {
		val row = rowNums[i]
		for (col in if (i.and(1) == 0) 0 until C else C - 1 downTo 0) {
			if (cave[row][col] == 'x') {
				cave[row][col] = '.'
				checkClusters(cave, visited)
				sortCave(R, C, cave, visited)
				clearVisited(visited)
				break
			}
		}
	}
	printCave(R, C, cave)
}

private fun readInts(): List<Int> = readln().split(' ').map { it.toInt() }

private fun checkClusters(cave: MMC, visited: AAB) {
	val colSize = cave[0].size
	for (c in 0 until colSize) {
		checkCluster(cave.lastIndex to c, cave, visited)
	}
}

private fun checkCluster(point: PII, cave: MMC, visited: AAB): MutableList<PII> {
	val (row, col) = point
	if (cave[row][col] == '.' || visited[row][col]) {
		return mutableListOf()
	}
	val positions = mutableListOf(point)
	val queue = LinkedList<PII>()
	queue.push(point)
	while (!queue.isEmpty()) {
		val (nowR, nowC) = queue.pop()
		visited[nowR][nowC] = true
		repeat(dc.size) {
			val nextR = nowR + dr[it]
			val nextC = nowC + dc[it]
			if (canExplore(nextR, nextC, cave, visited)) {
				queue.push(nextR to nextC)
				positions.add(nextR to nextC)
			}
		}
	}
	return positions
}

private fun canExplore(nextR: Int, nextC: Int, cave: MMC, visited: AAB) =
	(nextR >= 0) && (nextR < cave.size) && (nextC >= 0) && (nextC < cave[0].size) && (cave[nextR][nextC] == 'x') && !visited[nextR][nextC]

private fun sortCave(R: Int, C: Int, cave: MMC, visited: AAB) {
	var canDownRows = 1
	val newClusterPositions = findNewCluster(R, C, cave, visited)
	if (newClusterPositions.isEmpty()) return
	while (true) {
		val canDown =
			newClusterPositions.all { (row, col) ->
				row + canDownRows < R && !visited[row + canDownRows][col]
			}
		if (!canDown) {
			break
		} else {
			canDownRows++
		}
	}
	newClusterPositions.forEach { (row, col) ->
		cave[row][col] = '.'
	}
	newClusterPositions.forEach { (row, col) ->
		cave[row + canDownRows - 1][col] = 'x'
	}
}

private fun findNewCluster(R: Int, C: Int, cave: MMC, visited: AAB): MutableList<PII> {
	val newClusterPositions = mutableListOf<PII>()
	for (row in 0 until R) {
		for (col in 0 until C) {
			if (cave[row][col] == 'x' && !visited[row][col]) {
				newClusterPositions.add(row to col)
			}
		}
	}
	return newClusterPositions
}

private fun clearVisited(visited: Array<Array<Boolean>>) {
	for (row in visited.indices) {
		for (col in visited[0].indices) {
			visited[row][col] = false
		}
	}
}

private fun printCave(R: Int, C: Int, cave: MMC) {
	for (row in 0 until R) {
		for (col in 0 until C) {
			print(cave[row][col])
		}
		println()
	}
}
