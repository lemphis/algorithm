use std::io::{self, Read};

const DIVISOR: usize = 1_000_000_007;

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().flat_map(str::parse::<usize>);
    let n = it.next().unwrap();
    let mut memo = [0; 1_000_001];
    memo[1] = 1;
    print!("{}", fibo(n, &mut memo));
}

fn fibo(n: usize, memo: &mut [usize]) -> usize {
    match n {
        0..=1 => memo[n],
        n => {
            if memo[n] == 0 {
                memo[n] = (fibo(n - 1, memo) % DIVISOR + fibo(n - 2, memo) % DIVISOR) % DIVISOR;
            }
            memo[n]
        }
    }
}