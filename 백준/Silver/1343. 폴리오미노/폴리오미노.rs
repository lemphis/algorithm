use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let input = input
        .split_ascii_whitespace()
        .next()
        .unwrap()
        .replace("XXXX", "AAAA")
        .replace("XX", "BB");
    print!("{}", if input.contains("X") { "-1" } else { &input });
}