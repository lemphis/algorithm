import java.util.Arrays;

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42747">H-Index</a>
 */
class P42747 {

    public int solution(int[] citations) {
        Arrays.sort(citations);
        int answer = 0;
        int length = citations.length;
        for (int i = length - 1; i >= 0; --i) {
            int min = Math.min(citations[i], length - i);
            if (min > answer) {
                answer = min;
            }
        }

        return answer;
    }

}