import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * @see <a href="https://www.acmicpc.net/problem/11328">Strfry</a>
 */
public class P11328 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int count = Integer.parseInt(reader.readLine());

        for (int i = 0; i < count; ++i) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            String first = toSortedString(tokenizer.nextToken());
            String second = toSortedString(tokenizer.nextToken());
            System.out.println(first);
            System.out.println(second);
            System.out.println(first == second);
            // System.out.println(canApply ? "Possible" : "Impossible");
        }

    }

    static String toSortedString(String str) {
        char[] charArr = str.toCharArray();
        Arrays.sort(charArr);
        return charArr.toString();
    }

}