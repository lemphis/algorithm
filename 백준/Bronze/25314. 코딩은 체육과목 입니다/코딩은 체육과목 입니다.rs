use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let _ = stdin().read_to_string(&mut input);
    let mut output = String::new();
    let input = input
        .split_ascii_whitespace()
        .next()
        .unwrap()
        .parse::<i32>()
        .unwrap();
    for _ in 0..(input / 4) {
        output.push_str("long ")
    }
    output.push_str("int");
    println!("{}", output);
}
