import java.text.DecimalFormat
import kotlin.math.PI

fun main() {
	val decimalFormat = DecimalFormat("#.000000")
	val R = readln().toDouble()
	println(decimalFormat.format(R * R * PI))
	println(decimalFormat.format(R * R * 2))
}