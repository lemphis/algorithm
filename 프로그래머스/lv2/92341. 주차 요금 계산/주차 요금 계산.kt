import kotlin.math.ceil

class Solution {
    fun solution(fees: IntArray, records: Array<String>): IntArray {
        val (baseTime, baseFee, unitTime, unitFee) = fees
        val mapValues = records.map { it.split(" ") }
            .groupBy(
                { it[1] },
                {
                    Pair(it[0].split(":").map { num -> num.toInt() }
                        .mapIndexed { idx, s -> if (idx == 0) s * 60 else s }.sum(), it[2])
                }
            )
            .mapValues { entry -> entry.value.sortedBy { it.first } }
            .toSortedMap()

        val ans = mutableListOf<Int>()
        for ((key, value) in mapValues) {
            val newValue = value.toMutableList()
            if (value.size.and(1) == 1) {
                newValue.add(Pair(60 * 24 - 1, "OUT"))
            }
            var totalTime = 0
            for ((idx, pair) in newValue.withIndex()) {
                val (time, log) = pair
                if (idx.and(1) == 1) {
                    totalTime += (time - newValue[idx - 1].first)
                }
            }
            val sum = baseFee + ceil(((totalTime - baseTime).toDouble() / unitTime)).toInt() * unitFee
            ans.add(if (sum < baseFee) baseFee else sum)
        }
        return ans.toIntArray()
    }
}