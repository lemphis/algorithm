use std::{
    cmp::min,
    i32,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let n = it.next().unwrap();
    let mut dp = vec![i32::MAX; 100_001];
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for i in 6..n + 1 {
        dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
    }
    print!("{}", if dp[n] > 100_000_000 { -1 } else { dp[n] });
}