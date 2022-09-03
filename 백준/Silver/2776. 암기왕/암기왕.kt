fun main(args: Array<String>) {
    val T = readln().toInt()
    for (i in 0 until T) {
        val note = mutableSetOf<Int>()
        readln()
        readln().split(' ').forEach { note.add(it.toInt()) }
        readln()
        val stringBuilder = StringBuilder()
        readln().split(' ').forEach { stringBuilder.append((if (note.contains(it.toInt())) 1 else 0)).append("\n") }
        print(stringBuilder)
    }
}