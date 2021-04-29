import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/10001">Hash</a>
 */
public class P10001 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int wordLength = Integer.parseInt(tokenizer.nextToken()); // n
        int hash = Integer.parseInt(tokenizer.nextToken()); // k
        int exponent = Integer.parseInt(tokenizer.nextToken()); // m

        System.out.print(getHash(wordLength, hash, exponent));
    }

    private static int getHash(int wordLength, int hash, int exponent) {
        Map<String, Integer> cache = new HashMap<>(); 
        int count = 0;

        // TODO: 결과 출력 과정 작성

        return count;
    }

    private enum Alphabet {
        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
    }

}