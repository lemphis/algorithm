import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @see <a href="https://www.acmicpc.net/problem/1267">핸드폰 요금</a>
 */
public class P1267 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int callCount = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sameCount = 0;
        int mCount = 0;
        int total = 0;
        for (int i = 0; i < callCount; ++i) {
            int token = Integer.parseInt(st.nextToken());
            int quotient = token / 60;
            int remainder = token % 120;
            total += quotient * 30;
            if (remainder > 0) total += 20;
            if (remainder >= 60 && remainder < 90) {
                sameCount++;
            } else {
                mCount++;
            }
        }
        System.out.print(mCount > sameCount ? "M " : "Y M ");
        System.out.print(total);
    }

}