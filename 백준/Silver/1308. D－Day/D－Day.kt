import java.io.BufferedReader
import java.io.InputStreamReader
import java.time.LocalDate
import java.time.temporal.ChronoUnit

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (nowY, nowM, nowD) = br.readLine().split(' ').map { it.toInt() }
    val now = LocalDate.of(nowY, nowM, nowD)
    val (ddayY, ddayM, ddayD) = br.readLine().split(' ').map { it.toInt() }
    val dday = LocalDate.of(ddayY, ddayM, ddayD)
    if (dday.minusYears(1000).isAfter(now) || dday.minusYears(1000).isEqual(now)) {
        print("gg")
    } else {
        print("D" + ChronoUnit.DAYS.between(dday, now))
    }
}