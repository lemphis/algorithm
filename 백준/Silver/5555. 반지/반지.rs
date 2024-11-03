use std::io::{self, stdin};

fn main() {
    let buf = io::read_to_string(stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let s = input.next().unwrap();
    let rings = input.skip(1).map(|ring| ring.repeat(2)).collect::<Vec<_>>();
    print!("{}", rings.iter().filter(|ring| ring.contains(&s)).count());
}