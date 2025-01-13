use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (_, s) = (f().parse::<usize>().unwrap(), f());
    let count = s
        .chars()
        .collect::<Vec<_>>()
        .windows(2)
        .filter(|w| **w == ['E', 'W'])
        .count();
    print!("{count}");
}