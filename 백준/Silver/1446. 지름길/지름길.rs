use std::io::{self, BufReader, Read};

fn main() {
    let mut buf = String::with_capacity(1024 * 1024);
    BufReader::new(io::stdin().lock())
        .read_to_string(&mut buf)
        .unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, d) = (f(), f());
    let shortcuts: Vec<_> = (0..n).map(|_| (f(), f(), f())).collect();
    let mut dp = vec![0; d + 1];
    for i in 1..=d {
        let mut min_cost = dp[i - 1] + 1;
        for &(s, e, w) in shortcuts.iter() {
            if i == e {
                min_cost = min_cost.min(dp[s] + w);
            }
        }
        dp[i] = min_cost;
    }

    print!("{}", dp[d]);
}