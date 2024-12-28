use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, m) = (f(), f());
    let map = (0..n)
        .map(|_| (0..m).map(|_| f()).collect::<Vec<_>>())
        .collect::<Vec<_>>();
    let mut dp = vec![vec![vec![usize::MAX; m]; n]; 3];
    for d in 0..3 {
        for i in 0..m {
            dp[d][0][i] = map[0][i];
        }
    }
    for r in 1..n {
        for c in 0..m {
            if c > 0 {
                dp[0][r][c] =
                    dp[0][r][c].min(map[r][c] + dp[1][r - 1][c - 1].min(dp[2][r - 1][c - 1]));
            }
            if c + 1 < m {
                dp[2][r][c] =
                    dp[2][r][c].min(map[r][c] + dp[0][r - 1][c + 1].min(dp[1][r - 1][c + 1]));
            }
            dp[1][r][c] = dp[1][r][c].min(map[r][c] + dp[0][r - 1][c].min(dp[2][r - 1][c]));
        }
    }
    print!(
        "{}",
        dp.iter()
            .map(|r| r.last().unwrap().iter().min().unwrap())
            .min()
            .unwrap()
    );
}