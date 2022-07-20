class Solution {
	/**
	 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42888">오픈채팅방</a>
	 */
	fun solution(record: Array<String>): Array<String> {
		val map = mutableMapOf<String, String>()
		val splittedRecords = record.map { it.split(' ') }
		splittedRecords.forEach { if (it.size > 2) map[it[1]] = it[2] }
		return splittedRecords.filter { it[0] != "Change" }
			.map { (type, uid) -> "${map[uid]}님이 ${if (type == "Enter") "들어왔습니다." else "나갔습니다."}" }
			.toTypedArray()
	}
}