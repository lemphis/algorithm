import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/13300">방 배정</a>
 */
public class P13300 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int[][] grades = new int[2][6];
        int studentNum = Integer.parseInt(tokenizer.nextToken());
        int max = Integer.parseInt(tokenizer.nextToken());

        for (int i = 0; i < studentNum; ++i) {
            tokenizer = new StringTokenizer(reader.readLine());
            int gender = Integer.parseInt(tokenizer.nextToken());
            int grade = Integer.parseInt(tokenizer.nextToken());
            grades[gender][grade - 1]++;
        }

        int minRoomCount = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 6; ++j) {
                minRoomCount += Math.ceil((double)grades[i][j] / (double)max);
            }
        }

        System.out.println(minRoomCount);
    }

}