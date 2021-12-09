import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/42839">소수 찾기</a>
 */
class P42839 {

    private static int MAX = 10_000_000;
    private static Set<Integer> items = new HashSet<>();

    public int solution(String numbers) {
        boolean[] isPrime = new boolean[MAX];
        Arrays.fill(isPrime, true);
        for (int i = 2; i < MAX; ++i) {
            int times = 2;
            while (i * times < MAX) {
                isPrime[i * times++] = false;
            }
        }

        int answer = 0;
        boolean visited[] = new boolean[numbers.length()];
        dfs(numbers, 0, 0, visited);
        for (int item : items) {
            if (isPrime[item] == true) {
                answer++;
            }
        }

        return answer;
    }

    private void dfs(String numbers, int temp, int count, boolean[] visited) {
        if (count > 0) {
            if (temp != 0 && temp != 1) {
                items.add(temp);
            }
            if (count == numbers.length()) {
                return;
            }
        }

        for (int i = 0; i < numbers.length(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(numbers, Integer.parseInt("" + temp + (numbers.charAt(i) - '0')), count + 1, visited);
                visited[i] = false;
            }
        }
    }

}
