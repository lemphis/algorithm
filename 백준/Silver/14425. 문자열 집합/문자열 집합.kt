fun main(args: Array<String>) {
	val (N, M) = readLine()!!.split(' ').map { it.toInt() }
	val set = mutableSetOf<String>()
	for (i in 0 until N) set.add(readLine()!!)
	var count = 0
	for (i in 0 until M) if (set.contains(readLine()!!)) count++
	println(count)
}