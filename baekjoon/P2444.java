import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/2444">별 찍기 - 6</a>
 * 
 */
public class P2444 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(reader.readLine());
        int totalLineNum = input * 2 - 1;

        for (int i = 1; i <= totalLineNum; ++i) {
            for (int j = 0; j < input - i; ++j) {
                System.out.print(" ");
            }
            for (int j = 0; j < totalLineNum; ++j) {
                System.out.print("*");
            }
            for (int j = 0; j < i - input; ++j) {
                System.out.print(" ");
            }
            System.out.println();
        }
    }

}