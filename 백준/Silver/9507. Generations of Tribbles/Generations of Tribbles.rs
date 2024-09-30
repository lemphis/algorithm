use std::{fmt::Write, io};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().flat_map(str::parse::<usize>);
    let t = input.next().unwrap();
    let mut dp = vec![1usize; 68];
    dp[2] = 2;
    dp[3] = 4;
    for i in 4..68 {
        dp[i] = dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    let mut output = String::new();
    for _ in 0..t {
        writeln!(output, "{}", dp[input.next().unwrap()]).unwrap();
    }
    print!("{output}");
}