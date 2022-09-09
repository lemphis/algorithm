fun main() {
	val N = readln().toLong()
	val nums = readln().split(' ').map { it.toInt() }.toMutableList()
	if (N == 1L) {
		println(nums.sorted().dropLast(1).sum())
		return
	}
	val (a, b, c) = findMinAndRemove(nums)
	println(((N - 1) * (N - 2) * 4 * a) + ((N - 1) * (a + b) * 4) + ((a + b + c) * 4) + ((a + b) * (N - 2) * 4) + (a * ((N - 2) * (N - 2))))
}

fun findMinAndRemove(nums: MutableList<Int>): MutableList<Int> {
	val minNums = mutableListOf<Int>()
	repeat(3) {
		val min = nums.minOrNull()!!
		val minIndex = nums.indexOf(min)
		val restIndex = nums.lastIndex - minIndex
		if (minIndex > restIndex) {
			nums.removeAt(minIndex)
			nums.removeAt(restIndex)
		} else {
			nums.removeAt(restIndex)
			nums.removeAt(minIndex)
		}
		minNums.add(min)
	}
	return minNums
}