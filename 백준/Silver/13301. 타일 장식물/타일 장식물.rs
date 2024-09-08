use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut dp = [0usize; 81];
    dp[1] = 1;
    for i in 2..81 {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    print!("{}", dp[n] * 4 + dp[n - 1] * 2);
}