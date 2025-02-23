use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let t = f();
    let mut output = String::new();
    for _ in 0..t {
        let n = f();
        let stickers: Vec<Vec<_>> = (0..2).map(|_| (0..n).map(|_| f()).collect()).collect();
        let mut dp = vec![vec![0; n]; 2];
        for c in 0..n {
            dp[0][c] = stickers[0][c];
            dp[1][c] = stickers[1][c];
            if c > 0 {
                dp[0][c] = dp[0][c].max(dp[1][c - 1] + stickers[0][c]);
                dp[1][c] = dp[1][c].max(dp[0][c - 1] + stickers[1][c]);
            }
            if c > 1 {
                dp[0][c] = dp[0][c].max(dp[1][c - 2] + stickers[0][c]);
                dp[1][c] = dp[1][c].max(dp[0][c - 2] + stickers[1][c]);
            }
        }
        let mut max_sum = dp[0][n - 1].max(dp[1][n - 1]);
        if n > 1 {
            max_sum = max_sum.max(dp[0][n - 2].max(dp[1][n - 2]));
        }
        output.push_str(&format!("{max_sum}\n"));
    }
    print!("{output}");
}