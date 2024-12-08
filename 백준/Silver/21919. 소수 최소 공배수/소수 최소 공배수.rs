use std::{
    collections::HashSet,
    io::{self, stdin},
};

const MAX: usize = 1_000_001;

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let nums = (0..n).map(|_| f()).collect::<Vec<_>>();
    let mut is_prime = [true; MAX];
    for i in 2..(MAX as f64).sqrt() as usize + 1 {
        if is_prime[i] {
            let mut times = 2;
            while i * times < MAX {
                is_prime[i * times] = false;
                times += 1;
            }
        }
    }
    let ans = nums
        .iter()
        .filter(|&&num| is_prime[num])
        .collect::<HashSet<_>>()
        .into_iter()
        .fold(1, |acc, &cur| acc * cur);
    if ans == 1 {
        print!("-1");
        return;
    }
    print!("{ans}");
}