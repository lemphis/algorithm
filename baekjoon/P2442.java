import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @see <a href="https://www.acmicpc.net/problem/2442">별 찍기 - 5</a>
 * 
 */
public class P2442 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int totalLineNum = Integer.parseInt(reader.readLine());

        int maxCol = totalLineNum * 2 - 1;
        for (int row = 1; row <= totalLineNum; ++row) {
            for (int col = 1; col <= maxCol; ++col) {
                boolean canPrintStar = totalLineNum - row < col && col <= totalLineNum + row - 1;
                System.out.print(canPrintStar ? "*" : " ");
                if (col == totalLineNum + row)
                    break;
            }
            System.out.println();
        }
    }

}