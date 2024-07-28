use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let k: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let mut sensors: Vec<i32> = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    if k >= n {
        println!("0");
        return;
    }

    sensors.sort_unstable();

    let mut diffs: Vec<i32> = sensors.windows(2).map(|w| w[1] - w[0]).collect();

    diffs.sort_unstable_by(|a, b| b.cmp(a));

    let result: i32 = diffs.iter().skip(k - 1).sum();
    println!("{}", result);
}