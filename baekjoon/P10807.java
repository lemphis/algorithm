import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/10807">개수 세기</a>
 */
public class P10807 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        reader.readLine(); // useless
        int[] numArr = new int[201];

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        while (tokenizer.hasMoreTokens()) {
            numArr[Integer.parseInt(tokenizer.nextToken()) + 100]++;
        }

        int target = Integer.parseInt(reader.readLine());
        System.out.print(numArr[target + 100]);
    }

}