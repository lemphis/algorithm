import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/10093">숫자</a>
 */
public class P10093 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] inputs = new long[2];
        for (int i = 0; i < 2; ++i)
            inputs[i] = Long.parseLong(st.nextToken());
        if (inputs[0] == inputs[1]) {
            System.out.println(0);
            return;
        }
        Arrays.sort(inputs);
        System.out.println(inputs[1] - inputs[0] - 1);
        StringBuilder sb = new StringBuilder();
        for (long i = inputs[0] + 1; i < inputs[1]; ++i)
            sb.append(i + " ");
        System.out.println(sb.toString());
    }

}