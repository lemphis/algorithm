use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let prices = input.collect::<Vec<_>>();
    let mut dp = vec![0; n];
    for i in 0..n {
        dp[i] = prices[i];
        for j in 0..i {
            dp[i] = dp[i].min(dp[j] + prices[i - j - 1]);
        }
    }
    print!("{}", dp[n - 1]);
}
