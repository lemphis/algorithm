use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let mut powers: Vec<usize> = (0..n * 2).map(|_| f()).collect();
    powers.sort_unstable();
    print!(
        "{}",
        (0..n)
            .map(|i| powers[i] + powers[n * 2 - 1 - i])
            .min()
            .unwrap()
    );
}