import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * @see <a href="https://www.acmicpc.net/problem/2587">대표값2</a>
 */
public class P2587 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] inputs = new int[5];
        int average = 0;
        for (int i = 0; i < 5; ++i) {
            int inputNum = Integer.parseInt(br.readLine());
            inputs[i] = inputNum;
            average += inputNum;
        }
        Arrays.sort(inputs);
        System.out.println(average / 5);
        System.out.println(inputs[(int) Math.ceil(inputs.length / 2)]);
    }

}