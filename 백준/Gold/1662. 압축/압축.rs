use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_to_string(&mut input);
    let mut input = input.split_ascii_whitespace();
    let compressed = input.next().unwrap();
    let mut lens = vec![0; compressed.len()];
    let mut repeats = vec![0; compressed.len()];
    let mut depth = 0;
    for ch in compressed.chars() {
        match ch {
            '(' => {
                lens[depth] -= 1;
                depth += 1;
            }
            ')' => {
                lens[depth - 1] += lens[depth] * repeats[depth - 1];
                lens[depth] = 0;
                depth -= 1;
            }
            num => {
                lens[depth] += 1;
                repeats[depth] = num.to_digit(10).unwrap();
            }
        }
    }
    print!("{}", lens[0]);
}