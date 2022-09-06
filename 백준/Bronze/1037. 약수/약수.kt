import kotlin.math.pow

fun main() {
	readln()
	val nums = readln().split(' ').map { it.toInt() }.sorted()
	println(if (nums.size % 2 == 0) nums.first() * nums.last() else nums[nums.size / 2].toDouble().pow(2).toInt())
}