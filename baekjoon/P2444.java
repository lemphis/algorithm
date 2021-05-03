import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/2444">별 찍기 - 7</a>
 */
public class P2444 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(reader.readLine());
        int totalLineNum = input * 2 - 1;

        for (int i = 1; i <= totalLineNum; ++i) {
            int spaceCount = Math.abs(input - i);
            for (int j = 0; j < spaceCount; ++j) {
                System.out.print(" ");
            }

            int topStarCount = i * 2 - 1;
            for (int j = 0; j < topStarCount && i <= input; ++j) {
                System.out.print("*");
            }

            int bottomStarCount = (input * 2 - i) * 2 - 1;
            for (int j = 0; j < bottomStarCount && i > input; ++j) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

}