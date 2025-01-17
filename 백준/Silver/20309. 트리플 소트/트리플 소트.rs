use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let mut f = || input.next().unwrap();
    let n = f();
    let condition = (0..n)
        .map(|_| f())
        .enumerate()
        .all(|(i, num)| (i + 1) & 1 == num & 1);
    print!("{}", if condition { "YES" } else { "NO" });
}