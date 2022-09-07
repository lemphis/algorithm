import kotlin.math.round

fun main() {
	val nums = mutableListOf<Int>()
	repeat(readln().toInt()) { nums.add(readln().toInt()) }
	nums.sort()
	println(round(nums.sum().toDouble() / nums.size.toDouble()).toInt())
	println(nums[nums.size / 2])
	val entries = nums.groupingBy { it }.eachCount()
	var maxValue = 0
	entries.forEach { if (it.value > maxValue) maxValue = it.value }
	val list = entries.filter { it.value == maxValue }.toSortedMap().toList()
	println(if (list.size > 1) list[1].first else list[0].first)
	println(nums.last() - nums.first())
}