fun main() {
	readln()
	val classes = readln().split(' ').map { it.toLong() }
	val (B, C) = readln().split(' ').map { it.toLong() }
	println(classes.map { it - B }.filter { it > 0 }.sumOf { it / C + if (it % C > 0) 1 else 0 } + classes.size)
}