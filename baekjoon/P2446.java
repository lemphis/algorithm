import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/2446">별 찍기 - 9</a>
 */
public class P2446 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(reader.readLine());
        int totalLineNum = input * 2 - 1;

        for (int row = 1; row <= input; ++row) {
            for (int col = 1; col < row; ++col) {
                System.out.print(" ");
            }
            int starCount = totalLineNum - (row - 1) * 2;
            for (int col = 1; col <= starCount; ++col) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int row = 1; row < input; ++row) {
            int spaceCount = input - row;
            for (int col = 1; col < spaceCount; ++col) {
                System.out.print(" ");
            }
            int starCount = (row + 1) * 2 - 1;
            for (int col = 1; col <= starCount; ++col) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

}