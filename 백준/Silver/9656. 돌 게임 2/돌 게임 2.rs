use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<u64>);
    let n = input.next().unwrap();
    print!("{}", if n & 1 == 0 { "SK" } else { "CY" });
}