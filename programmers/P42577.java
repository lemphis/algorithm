import java.util.Arrays;

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42577">전화번호 목록</a>
 */
class P42577 {

    public static boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        int limit = phone_book.length - 1;
        for (int i = 0; i < limit; ++i) {
            if (phone_book[i + 1].startsWith(phone_book[i]))
                return false;
        }
        return true;
    }

}
