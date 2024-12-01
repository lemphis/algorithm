use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut dp = vec![1; n + 1];
    for i in 2..=n {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1_000_000_007;
    }
    print!("{}", dp[n]);
}