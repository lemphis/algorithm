import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/11328">Strfry</a>
 */
public class P11328 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int count = Integer.parseInt(reader.readLine());

        for (int i = 0; i < count; ++i) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            char[] first = tokenizer.nextToken().toCharArray();
            char[] second = tokenizer.nextToken().toCharArray();
            Arrays.sort(first);
            Arrays.sort(second);
            int length = first.length;
            boolean canApply = true;
            for (int j = 0; j < length; ++j) {
                if (first[j] != second[j]) {
                    canApply = false;
                    break;
                }
            }
            System.out.println(canApply ? "Possible" : "Impossible");
        }

    }

}