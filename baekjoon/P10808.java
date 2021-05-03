import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/10808">알파벳 개수</a>
 */
public class P10808 {

    private static final int ASCII_LOWERCASE_OFFSET = 97;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String input = reader.readLine();

        int[] counts = new int[26];

        for (char alphabet : input.toCharArray()) {
            counts[alphabet - ASCII_LOWERCASE_OFFSET]++;
        }

        for (int count : counts) {
            System.out.print(count + " ");
        }
    }

}