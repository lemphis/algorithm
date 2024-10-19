use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<u128>);
    let n = input.next().unwrap();
    let mut dp = [0u128; 36];
    dp[0] = 1;
    dp[1] = 1;
    for i in 2..=n {
        for j in 0..i {
            dp[i as usize] += dp[j as usize] * dp[(i - 1 - j) as usize];
        }
    }
    print!("{}", dp[n as usize]);
}