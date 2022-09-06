fun main() {
	val burgers = mutableListOf<Int>()
	val drinks = mutableListOf<Int>()
	repeat(3) { burgers.add(readln().toInt()) }
	repeat(2) { drinks.add(readln().toInt()) }
	println(burgers.minOf { it } + drinks.minOf { it } - 50)
}