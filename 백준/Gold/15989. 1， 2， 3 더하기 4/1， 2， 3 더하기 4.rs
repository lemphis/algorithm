use std::io::{self, stdin};

const MAX: usize = 10_001;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut dp = [1; MAX];
    for i in 2..MAX {
        dp[i] += dp[i - 2];
    }
    for i in 3..MAX {
        dp[i] += dp[i - 3];
    }
    let mut output = String::new();
    for _ in 0..n {
        output.push_str(&format!("{}\n", dp[f()]));
    }
    print!("{output}");
}