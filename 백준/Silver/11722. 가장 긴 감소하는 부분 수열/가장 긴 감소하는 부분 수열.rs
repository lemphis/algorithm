use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let nums = input.collect::<Vec<_>>();
    let mut dp = vec![1; n];
    let mut max = 1;
    for i in 0..n - 1 {
        for j in i + 1..n {
            if nums[i] > nums[j] && dp[i] == dp[j] {
                dp[j] = dp[i] + 1;
                max = max.max(dp[j]);
            }
        }
    }
    print!("{max}");
}