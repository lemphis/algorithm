use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut dp = [0usize; 117];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for i in 4..=n {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    print!("{}", dp[n]);
}