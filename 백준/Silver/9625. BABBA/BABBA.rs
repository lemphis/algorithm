use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let k = it.next().unwrap();
    let mut dp = [(0, 0); 46];
    dp[0] = (1, 0);
    dp[1] = (0, 1);
    for i in 2..=k {
        dp[i] = (dp[i - 2].0 + dp[i - 1].0, dp[i - 2].1 + dp[i - 1].1);
    }
    print!("{} {}", dp[k].0, dp[k].1);
}