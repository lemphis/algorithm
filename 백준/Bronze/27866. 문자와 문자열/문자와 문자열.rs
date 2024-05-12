use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let s = input.next().unwrap();
    let i = input.next().unwrap().parse::<usize>().unwrap();
    print!("{}", s.chars().nth(i - 1).unwrap());
}