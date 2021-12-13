/**
 * @see <a href="https://programmers.co.kr/learn/courses/30/lessons/43162">네트워크</a>
 */
class P43162 {

    private int[] parents;

    public int solution(int n, int[][] computers) {
        parents = new int[n];
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }

        int answer = n;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (computers[r][c] == 1 && find(r) != find(c)) {
                    union(r, c);
                    answer--;
                }
            }
        }

        return answer;
    }

    private int find(int x) {
        return x == parents[x] ? x : (parents[x] = find(parents[x]));
    }

    private void union(int x, int y) {
        parents[find(x)] = find(y);
    }

}
