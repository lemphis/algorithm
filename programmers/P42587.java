import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42587">프린터</a>
 */
class P42587 {

    public int solution(int[] priorities, int location) {
        int answer = 1;
        Queue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder());
        for (int element : priorities) {
            queue.add(element);
        }
        return answer;
    }

}
