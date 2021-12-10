import java.util.ArrayList;

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42842">카펫</a>
 */
class P42842 {

    public int[] solution(int brown, int yellow) {
        int carpetWidth = brown + yellow;
        ArrayList<Integer> divisors = new ArrayList<>();
        for (int i = 3; i <= (int) Math.sqrt(carpetWidth); ++i) {
            if (carpetWidth % i == 0) {
                divisors.add(i);
            }
        }
        int[] answer = new int[2];
        for (int i = 0; i < divisors.size(); ++i) {
            if ((divisors.get(i) - 2) * (carpetWidth / divisors.get(i) - 2) == yellow) {
                answer[0] = carpetWidth / divisors.get(i);
                answer[1] = divisors.get(i);
            }
        }
        
        return answer;
    }

}
