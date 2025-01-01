use std::io::{self, stdin};

const MOD: usize = 10_007;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let (times, mut count) = (n / 4, 0);
    for i in 1..=times {
        let now_count = combination(13, i) * combination(52 - (i * 4), n - (i * 4)) % MOD;
        if i & 1 == 1 {
            count = (count + now_count) % MOD;
        } else {
            count = (count + MOD - now_count) % MOD;
        }
    }
    print!("{}", count % MOD);
}

fn combination(n: usize, k: usize) -> usize {
    if k > n {
        return 0;
    }
    let min = k.min(n - k);
    (0..min).fold(1, |acc, i| acc * (n - i) / (i + 1))
}