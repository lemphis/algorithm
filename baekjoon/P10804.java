import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

/**
 * @see <a href="https://www.acmicpc.net/problem/10804">카드 역배치</a>
 */
public class P10804 {

    public static void main(String[] args) throws IOException {
        int[] answer = solution();
        print(answer);
    }

    static int[] solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] cards = IntStream.rangeClosed(1, 20).toArray();

        for (int i = 0; i < 10; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            int newLength = to - from;
            int[] temp = Arrays.copyOfRange(cards, from, to + 1);
            for (int j = 0; j <= newLength; ++j) {
                cards[from + j] = temp[newLength - j];
            }
        }

        return cards;
    }

    static void print(int[] items) {
        for (int item : items) {
            System.out.print(item + " ");
        }
    }

}
