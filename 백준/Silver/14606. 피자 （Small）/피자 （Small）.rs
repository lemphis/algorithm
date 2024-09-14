use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let mut dp = [0; 11];
    for i in 1..dp.len() {
        dp[i] = dp[i - 1] + i - 1;
    }
    print!("{}", dp[n]);
}