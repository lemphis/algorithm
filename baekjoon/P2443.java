import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/2443">별 찍기 - 6</a>
 * 
 */
public class P2443 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int totalLineNum = Integer.parseInt(reader.readLine());

        for (int i = 0; i < totalLineNum; ++i) {
            for (int j = 0; j < i; ++j) {
                System.out.print(" ");
            }

            int starNum = (totalLineNum * 2) - ((i + 1) * 2 - 1);
            for (int j = 0; j < starNum; ++j) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

}