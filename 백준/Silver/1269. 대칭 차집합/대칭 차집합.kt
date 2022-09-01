fun main(args: Array<String>) {
	readln()
	val A = readln().split(' ')
	val B = readln().split(' ')
	println((A + B).groupBy { it }.filter { it.value.size == 1 }.count())
}