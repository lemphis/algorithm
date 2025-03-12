use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let (n, k) = (f(), f());
    let mut wines: Vec<_> = (0..n).map(|_| f()).collect();

    wines.sort_unstable();

    let mut sum = *wines.last().unwrap();
    for i in 0..(k - 1) / 2 {
        sum += wines[n - 2 - i] - wines[i];
    }

    print!("{sum}");
}