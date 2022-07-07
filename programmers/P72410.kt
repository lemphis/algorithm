/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/72410">신규 아이디 추천</a>
 */
fun solution(new_id: String): String = new_id.lowercase()
	.filter { it == '-' || it == '_' || it == '.' || it in 'a'..'z' || it in '0'..'9' }
	.replace("\\.{2,}".toRegex(), ".")
	.replace("^\\.".toRegex(RegexOption.MULTILINE), "")
	.replace("\\.\$".toRegex(RegexOption.MULTILINE), "")
	.ifEmpty { "a" }
	.run { if (this.length < 15) slice(0 until this.length) else slice(0 until 15) }
	.replace("\\.\$".toRegex(RegexOption.MULTILINE), "")
	.run {
		if (this.isEmpty()) return@run this
		val temp = StringBuilder(this)
		if (this.length <= 2) {
			while (temp.length < 3) temp.append(this.last())
		}
		temp.toString()
	}