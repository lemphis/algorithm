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
        int m = 0;
        int y = 0;
        for (int i = 0; i < callCount; ++i) {
            int token = Integer.parseInt(st.nextToken());
            m += 15 * (token / 60 + 1);
            y += 10 * (token / 30 + 1);
        }
        if (y > m) System.out.print("M ");
        else if (y < m) System.out.print("Y ");
        else System.out.print("Y M ");
        System.out.print(Math.min(m, y));
    }

}