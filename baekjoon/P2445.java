import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/2445">별 찍기 - 8</a>
 */
public class P2445 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(reader.readLine());

        for (int row = 1; row <= input; ++row) {
            for (int col = 1; col <= row; ++col) {
                System.out.print("*");
            }
            int spaceCount = (input - row) * 2;
            for (int col = 1; col <= spaceCount; ++col) {
                System.out.print(" ");
            }
            for (int col = 1; col <= row; ++col) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int row = 1; row < input; ++row) {
            int starCount = input - row;
            for (int col = 1; col <= starCount; ++col) {
                System.out.print("*");
            }
            int spaceCount = row * 2;
            for (int col = 1; col <= spaceCount; ++col) {
                System.out.print(" ");
            }
            for (int col = 1; col <= starCount; ++col) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

}