var num = ""

fun main() {
	dfs(readln().toInt())
}

fun dfs(N: Int) {
	if (num.length == N) {
		println(num)
		return
	}
	for (i in 1..9) {
		num += i.toString()
		if (isPrime(num.toInt())) {
			dfs(N)
		}
		num = num.dropLast(1)
	}
}

fun isPrime(num: Int): Boolean {
	if (num == 1) return false
	for (i in 2 until num) {
		if (num % i == 0) return false
	}
	return true
}