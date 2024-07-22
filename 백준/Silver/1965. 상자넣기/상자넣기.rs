use std::{
    cmp::max,
    io::{self, Read},
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let n = it.next().unwrap();
    let mut boxes = vec![0; n];
    let mut dp = vec![1; n];
    let mut ans = 1;
    for i in 0..n {
        boxes[i] = it.next().unwrap();
        for j in 0..i {
            if boxes[j] < boxes[i] {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    print!("{}", ans);
}