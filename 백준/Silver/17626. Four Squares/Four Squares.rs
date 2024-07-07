use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut dp = [0; 50001];
    for i in 1..=n {
        dp[i] = dp[i - 1] + 1;
        for j in (2..).take_while(|x| x * x <= i) {
            dp[i] = dp[i].min(dp[i - j * j] + 1);
        }
    }
    print!("{}", dp[n]);
}