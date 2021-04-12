import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/2480">주사위 세개</a>
 */
public class P2480 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int tokenCount = st.countTokens();
        int[] eyes = new int[tokenCount];
        for (int i = 0; i < tokenCount; ++i) {
            eyes[i] = Integer.parseInt(st.nextToken());
        }

        int answer = 0;
        if (eyes[0] == eyes[1] && eyes[1] == eyes[2]) {
            answer = 10000 + 1000 * eyes[0];
        } else if (eyes[0] == eyes[1] || eyes[0] == eyes[2]) {
            answer = 1000 + 100 * eyes[0];
        } else if (eyes[1] == eyes[2]) {
            answer = 1000 + 100 * eyes[1];
        } else {
            Arrays.sort(eyes);
            answer = 100 * eyes[2];
        }

        System.out.println(answer);
    }
}