use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut dp = [0usize; 36];
    dp[0] = 1;
    dp[1] = 1;
    for i in 2..=n {
        for j in 0..i {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    print!("{}", dp[n]);
}