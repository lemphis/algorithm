use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let mut f = || input.next().unwrap();
    let (_, s) = (f().parse::<usize>().unwrap(), f());
    let min_count = 1 + s
        .split('B')
        .filter(|s| !s.is_empty())
        .count()
        .min(s.split('R').filter(|s| !s.is_empty()).count());
    print!("{min_count}");
}