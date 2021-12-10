/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/43105">정수 삼각형</a>
 */
class P43105 {

    public int solution(int[][] triangle) {
        int len = triangle.length;
        int memo[][] = new int[len][len];

        memo[0][0] = triangle[0][0];
        int answer = memo[0][0];
        for (int r = 1; r < len; ++r) {
            for (int c = 0; c <= r; ++c) {
                memo[r][c] = triangle[r][c];
                if (c == 0) {
                    memo[r][c] += memo[r - 1][c];
                } else if (c == r) {
                    memo[r][c] += memo[r - 1][c - 1];
                } else {
                    int max_item = memo[r - 1][c - 1] < memo[r - 1][c] ? memo[r - 1][c] : memo[r - 1][c - 1];
                    memo[r][c] += max_item;
                }
                if (answer < memo[r][c]) {
                    answer = memo[r][c];
                }
            }
        }

        return answer;
    }

}
