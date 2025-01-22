use std::io::{self, stdin};

const MAX: usize = 15_500_001;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut is_prime = vec![true; MAX];
    for i in 2..=(MAX as f64).sqrt() as usize {
        if is_prime[i] {
            for j in (i * 2..MAX).into_iter().step_by(i) {
                is_prime[j] = false;
            }
        }
    }
    print!(
        "{}",
        is_prime
            .iter()
            .enumerate()
            .skip(2)
            .filter(|(_, p)| **p)
            .nth(n - 1)
            .unwrap()
            .0
    );
}